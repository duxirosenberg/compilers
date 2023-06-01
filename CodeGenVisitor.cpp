//////////////////////////////////////////////////////////////////////
//
//    CodeGenVisitor - Walk the parser tree to do
//                     the generation of code
//
//    Copyright (C) 2017-2023  Universitat Politecnica de Catalunya
//
//    This library is free software; you can redistribute it and/or
//    modify it under the terms of the GNU General Public License
//    as published by the Free Software Foundation; either version 3
//    of the License, or (at your option) any later version.
//
//    This library is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//    Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public
//    License along with this library; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
//
//    contact: José Miguel Rivero (rivero@cs.upc.edu)
//             Computer Science Department
//             Universitat Politecnica de Catalunya
//             despatx Omega.110 - Campus Nord UPC
//             08034 Barcelona.  SPAIN
//
//////////////////////////////////////////////////////////////////////

#include "CodeGenVisitor.h"
#include "antlr4-runtime.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/code.h"

#include <string>
#include <cstddef>    // std::size_t

// uncomment the following line to enable debugging messages with DEBUG*
//#define DEBUG_BUILD
#include "../common/debug.h"

// using namespace std;


// Constructor
CodeGenVisitor::CodeGenVisitor(TypesMgr       & Types,
                               SymTable       & Symbols,
                               TreeDecoration & Decorations) :
  Types{Types},
  Symbols{Symbols},
  Decorations{Decorations} {
}

// Accessor/Mutator to the attribute currFunctionType
TypesMgr::TypeId CodeGenVisitor::getCurrentFunctionTy() const {
  return currFunctionType;
}

void CodeGenVisitor::setCurrentFunctionTy(TypesMgr::TypeId type) {
  currFunctionType = type;
}

// Methods to visit each kind of node:
//
antlrcpp::Any CodeGenVisitor::visitProgram(AslParser::ProgramContext *ctx) {
  DEBUG_ENTER();
  code my_code;
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  for (auto ctxFunc : ctx->function()) { 
    subroutine subr = visit(ctxFunc);
    my_code.add_subroutine(subr);
  }
  Symbols.popScope();
  DEBUG_EXIT();
  return my_code;
}

antlrcpp::Any CodeGenVisitor::visitFunction(AslParser::FunctionContext *ctx) {
  DEBUG_ENTER();
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  subroutine subr(ctx->ID()->getText());
  codeCounters.reset();

  //get return type
  TypesMgr::TypeId func_type = getTypeDecor(ctx->basic_type());

  //add parameters
  if(ctx->basic_type()){
    subr.add_param("_result", Types.to_string(func_type),0);
  }
  std::vector<var> && lparams = visit(ctx->parameters());
  for (auto & var : lparams) {
    subr.add_param(var.name, var.type, var.nelem);
  }
  
  std::vector<var> && lvars = visit(ctx->declarations());
  for (auto & var : lvars) {
    subr.add_var(var);
  }
  instructionList && code = visit(ctx->statements());
  code = code || instruction(instruction::RETURN());
  subr.set_instructions(code);
  Symbols.popScope();
  DEBUG_EXIT();
  return subr;
}



antlrcpp::Any CodeGenVisitor::visitParameters(AslParser::ParametersContext *ctx){
  DEBUG_ENTER();
  //from vector get ID, type and calculate if it is an arraytype, then return those three attributes
  std::vector<var> lparams;
  for (size_t i = 0; i < ctx->ID().size(); i++) {
    std::string id = ctx->ID(i)->getText();
    TypesMgr::TypeId tid = getTypeDecor(ctx->type(i));
    bool isArray = Types.isArrayTy(tid);
    lparams.push_back(var(id, Types.to_string(tid), isArray));
  }

  DEBUG_EXIT();
  return lparams;
}


antlrcpp::Any CodeGenVisitor::visitReturnStmt(AslParser::ReturnStmtContext *ctx){
  DEBUG_ENTER();
  instructionList code;
  CodeAttribs     && codAtsE = visit(ctx->expr());
  std::string           addr = codAtsE.addr;
  // std::string           offs = codAtsE.offs;
  instructionList &     code1 = codAtsE.code;
  code = code1 || instruction::LOAD("_result",addr) //|| instruction::RETURN();
  DEBUG_EXIT();
  return code;
}




antlrcpp::Any CodeGenVisitor::visitDeclarations(AslParser::DeclarationsContext *ctx) {
  DEBUG_ENTER();
  std::vector<var> lvars;
  for (auto & varDeclCtx : ctx->variable_decl()) {
    //NEW CODE:
    std::vector<var> list_vars = visit(varDeclCtx);
    for (auto & onevar : list_vars) {
      lvars.push_back(onevar);
    }
    //OLD CODE: var onevar = visit(varDeclCtx);
    //OLD CODE: lvars.push_back(onevar);
  }
  DEBUG_EXIT();
  return lvars;
}

antlrcpp::Any CodeGenVisitor::visitVariable_decl(AslParser::Variable_declContext *ctx) {
  DEBUG_ENTER();
  TypesMgr::TypeId   t1 = getTypeDecor(ctx->type());
  std::size_t      size = Types.getSizeOfType(t1);

  //START NEW CODE
  std::vector<var> lvars;
  for (auto & idCtx : ctx->ID()) {
    lvars.push_back(var{idCtx->getText(), Types.to_string(t1), size});
  }
  //END NEW CODE


  DEBUG_EXIT();
  //NEW:
  return lvars;
  //OLD CODE: return var{ctx->ID(0)->getText(), Types.to_string(t1), size};
}

antlrcpp::Any CodeGenVisitor::visitStatements(AslParser::StatementsContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  for (auto stCtx : ctx->statement()) {
    instructionList && codeS = visit(stCtx);
    code = code || codeS;
  }
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitAssignStmt(AslParser::AssignStmtContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  CodeAttribs     && codAtsE1 = visit(ctx->left_expr());
  std::string           addr1 = codAtsE1.addr;
  // std::string           offs1 = codAtsE1.offs;
  instructionList &     code1 = codAtsE1.code;
  // TypesMgr::TypeId tid1 = getTypeDecor(ctx->left_expr());
  CodeAttribs     && codAtsE2 = visit(ctx->expr());
  std::string           addr2 = codAtsE2.addr;
  // std::string           offs2 = codAtsE2.offs;
  instructionList &     code2 = codAtsE2.code;
  // TypesMgr::TypeId tid2 = getTypeDecor(ctx->expr());
  code = code1 || code2 || instruction::LOAD(addr1, addr2);
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitWhileStmt(AslParser::WhileStmtContext *ctx){
  DEBUG_ENTER();

  instructionList code;
  CodeAttribs     && codAtsE = visit(ctx->expr());
  std::string          addr1 = codAtsE.addr;
  instructionList &    code1 = codAtsE.code;
  instructionList &&   code2 = visit(ctx->statements());
  std::string label = "while"+codeCounters.newLabelWHILE(); 
  std::string labelEndWhile = "end"+label;
  code = instruction::LABEL(label) || code1 || instruction::FJUMP(addr1, labelEndWhile) ||
         code2 || instruction::UJUMP(label) || instruction::LABEL(labelEndWhile);
  DEBUG_EXIT();
  return code;  
}

antlrcpp::Any CodeGenVisitor::visitIfStmt(AslParser::IfStmtContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  CodeAttribs     && codAtsE = visit(ctx->expr());
  std::string          addr1 = codAtsE.addr;
  instructionList &    code1 = codAtsE.code;
  instructionList &&   code2 = visit(ctx->statements(0));
  std::string label = codeCounters.newLabelIF();
  std::string labelEndIf = "endif"+label;
  code = code1 || instruction::FJUMP(addr1, labelEndIf) ||
         code2 || instruction::LABEL(labelEndIf);
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitProcCall(AslParser::ProcCallContext *ctx) {
  DEBUG_ENTER();

  instructionList code;
  std::string name = ctx->ident()->getText();
  TypesMgr::TypeId type = getTypeDecor(ctx->ident());
  auto typesParams = Types.getFuncParamsTypes(type);

  instructionList pushParams;
  instructionList popParams;

  for(size_t i = 0; i < (ctx->expr()).size(); i++){
    CodeAttribs && codeAtParameter = visit(ctx->expr(i));
    std::string addr_param = codeAtParameter.addr;
    instructionList & code_param = codeAtParameter.code;
    TypesMgr::TypeId tP = getTypeDecor(ctx->expr(i));

    code = code || code_param;
    std::string param_temp = addr_param;

    if(Types.isFloatTy(typesParams[i]) and Types.isIntegerTy(tP)){
      //cast to Float
      auto temp = "%"+codeCounters.newTEMP();
      code = code || instruction::FLOAT(temp, addr_param);
    }
  }  
  
  //return for non-void functions
  if(not Types.isVoidTy(type)){
    pushParams = pushParams || instruction::PUSH();
    popParams = popParams || instruction::POP();
  }
  
  code = code || pushParams || instruction::CALL(name) || popParams;


  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitFunctionCall(AslParser::FunctionCallContext *ctx){
  DEBUG_ENTER();

  instructionList code;
  std::string name = ctx->ident()->getText();
  auto typesParams = Types.getFuncParamsTypes(getTypeDecor(ctx->ident()));
  int numParams = (ctx->expr()).size();
  
  instructionList pushParams; 
  instructionList popParams;


  for (int i = 0; i < numParams; i++){
    CodeAttribs && codeAtParameter = visit(ctx->expr(i));
    std::string addr_param = codeAtParameter.addr;
    instructionList & code_param = codeAtParameter.code;
    
    code = code || code_param;
    std::string param_temp = addr_param;

    TypesMgr::TypeId actual_type_param = getTypeDecor(ctx->expr(i));
    TypesMgr::TypeId formal_type_param = typesParams[i];

    //cast from int to float
    if(Types.isFloatTy(formal_type_param) && Types.isIntegerTy(actual_type_param)){
      param_temp = "%"+codeCounters.newTEMP();
      code = code || instruction::FLOAT(param_temp,addr_param);
    }

    pushParams = pushParams || instruction::PUSH(param_temp);
    popParams = popParams || instruction::POP();
  }
  

  code = code || instruction::PUSH() || pushParams;  //other params to push
  code = code|| instruction::CALL(name);

  //get return
  std::string temp = "%"+codeCounters.newTEMP();
  code = code || popParams || instruction::POP(temp);


  CodeAttribs codeAts(temp,"",code);

  DEBUG_EXIT();
  return codeAts;
}



antlrcpp::Any CodeGenVisitor::visitReadStmt(AslParser::ReadStmtContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAtsE = visit(ctx->left_expr());
  std::string          addr1 = codAtsE.addr;
  // std::string          offs1 = codAtsE.offs;
  instructionList &    code1 = codAtsE.code;
  instructionList &     code = code1;
  TypesMgr::TypeId tid1 = getTypeDecor(ctx->left_expr());
  if(Types.isFloatTy(tid1))
    code = code1 || instruction::READF(addr1);
  else if (Types.isCharacterTy(tid1))
    code = code1 || instruction::READC(addr1);
  else
    code = code1 || instruction::READI(addr1);
  DEBUG_EXIT();
  return code;
}


antlrcpp::Any CodeGenVisitor::visitWriteExpr(AslParser::WriteExprContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->expr());
  std::string         addr1 = codAt1.addr;
  // std::string         offs1 = codAt1.offs;
  instructionList &   code1 = codAt1.code;
  instructionList &    code = code1;
  TypesMgr::TypeId tid1 = getTypeDecor(ctx->expr());
  
  if (Types.isFloatTy(tid1)) {
    code = code1 || instruction::WRITEF(addr1);
  } else if (Types.isCharacterTy(tid1)){
    code = code1 || instruction::WRITEC(addr1);
  } else {
    code = code1 || instruction::WRITEI(addr1);
  }

  DEBUG_EXIT();
  return code;
}


antlrcpp::Any CodeGenVisitor::visitWriteString(AslParser::WriteStringContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  std::string s = ctx->STRING()->getText();
  code = code || instruction::WRITES(s);
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitLeft_expr(AslParser::Left_exprContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs && codAts = visit(ctx->ident());
  DEBUG_EXIT();
  return codAts;
}


antlrcpp::Any CodeGenVisitor::visitUnary(AslParser::UnaryContext *ctx){
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->expr());
  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;
  instructionList &   code = code1;
  TypesMgr::TypeId tid1 = getTypeDecor(ctx->expr());
  std::string temp = "%"+codeCounters.newTEMP();
  if(ctx->NOT()){
    code = code || instruction::NOT(temp, addr1);
  }else if (ctx->SUB()){
    if(Types.isIntegerTy(tid1)){
      code = code || instruction::NEG(temp, addr1);
    }else{
      code = code || instruction::FNEG(temp, addr1);
    }
  }

  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}



antlrcpp::Any CodeGenVisitor::visitArithmetic(AslParser::ArithmeticContext *ctx) {
  DEBUG_ENTER();
  //std::cout << "VisitArithmetic: Operation: "  <<ctx->op->getText() << std::endl;


  //std::cout << "first expr is being visited" << std::endl;
  CodeAttribs     && codAt1 = visit(ctx->expr(0));
  //std::cout << "first expr visited" << std::endl;

  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;
  //std::cout << "second expr is being visited" << std::endl;
  CodeAttribs     && codAt2 = visit(ctx->expr(1));
  //std::cout << "second expr visited" << std::endl;

  std::string         addr2 = codAt2.addr;
  instructionList &   code2 = codAt2.code;
  instructionList &&   code = code1 || code2;

  std::string temp = "%"+codeCounters.newTEMP();
//print for debugging
  //std::cout << "   Arg1: " << Types.to_string(getTypeDecor(ctx->expr(0)))  <<std::endl;
  //std::cout << "   Arg2: " << Types.to_string(getTypeDecor(ctx->expr(1))) <<std::endl;


  if(Types.isIntegerTy(getTypeDecor(ctx))){

    //return type is int, both args must be int
    //generate code for different ops
    
    if(ctx->MUL()) code = code || instruction::MUL(temp, addr1, addr2);
    else if (ctx->DIV()) code = code || instruction::DIV(temp, addr1, addr2);
    else if (ctx->PLUS()) code = code || instruction::ADD(temp, addr1, addr2);
    else if (ctx->SUB()) code = code || instruction::SUB(temp, addr1, addr2);
    else{
      //must be MOD, gen instructions to calc remainder
      code = code || instruction::DIV(temp, addr1, addr2)
      || instruction::MUL(temp, temp, addr2)
      || instruction::SUB(temp, addr1, temp);
    }
  }else{
    // return type is float, at least one arg must be float -> convert both to float
    TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
    TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
    
    if(Types.isIntegerTy(t1)){
      //convert first arg to float
      std::string temp2 = "%"+codeCounters.newTEMP();
      code = code || instruction::FLOAT(temp2, addr1);
      addr1 = temp2;
    }else if(Types.isIntegerTy(t2)){
      //convert second arg to float
      std::string temp2 = "%"+codeCounters.newTEMP();
      code = code || instruction::FLOAT(temp2, addr2);
      addr2 = temp2;
    }

    //generate code for different ops
    if(ctx->MUL()) code = code || instruction::FMUL(temp, addr1, addr2);
    else if (ctx->DIV()) code = code || instruction::FDIV(temp, addr1, addr2);
    else if (ctx->PLUS()) code = code || instruction::FADD(temp, addr1, addr2);
    else if (ctx->SUB()) code = code || instruction::FSUB(temp, addr1, addr2);
  }

  /* ---------OLD CODE--------------
  // TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  // TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  // TypesMgr::TypeId  t = getTypeDecor(ctx);
  std::string temp = "%"+codeCounters.newTEMP();
  if (ctx->MUL())
    code = code || instruction::MUL(temp, addr1, addr2);
  else // (ctx->PLUS())
    code = code || instruction::ADD(temp, addr1, addr2);
  */


  CodeAttribs codAts(temp, "", code);
  //std::cout << "   VisitArithmetic returns, result type: " << Types.to_string(getTypeDecor(ctx)) <<std::endl;
  //std::cout << codAts.code.dump() << std::endl;
  //std::cout << "   " <<codAts.addr << std::endl;


  DEBUG_EXIT();
  return codAts;

}


antlrcpp::Any CodeGenVisitor::visitLogical(AslParser::LogicalContext *ctx){
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->expr(0));
  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;
  CodeAttribs     && codAt2 = visit(ctx->expr(1));
  std::string         addr2 = codAt2.addr;
  instructionList &   code2 = codAt2.code;
  instructionList &&   code = code1 || code2;

  std::string temp = "%"+codeCounters.newTEMP();
  if(ctx->AND()){
    code = code || instruction::AND(temp, addr1, addr2);
  }else if (ctx->OR()){
    code = code || instruction::OR(temp, addr1, addr2);
  }

  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}




antlrcpp::Any CodeGenVisitor::visitRelational(AslParser::RelationalContext *ctx) {
  //std::cout << "Relational operator: " << ctx->op->getText() << std::endl;

  
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->expr(0));
  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;
  CodeAttribs     && codAt2 = visit(ctx->expr(1));
  std::string         addr2 = codAt2.addr;
  instructionList &   code2 = codAt2.code;
  instructionList &&   code = code1 || code2;
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  // TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  // TypesMgr::TypeId  t = getTypeDecor(ctx);
  std::string temp = "%"+codeCounters.newTEMP();
  if(Types.isIntegerTy(t1)){
    //both args are int
    if (ctx->EQ())
      code = code || instruction::EQ(temp, addr1, addr2);
    else if (ctx->NEQ())
      code = code || instruction::EQ(temp, addr1, addr2) || instruction::NOT(temp, temp);
    else if (ctx->L())
      code = code || instruction::LT(temp, addr1, addr2);
    else if (ctx->LE())
      code = code || instruction::LE(temp, addr1, addr2);
    else if (ctx->G())
      code = code || instruction::LE(temp, addr1, addr2) || instruction::NOT(temp,temp);
    else // (ctx->GEQ())
      code = code || instruction::LT(temp, addr1, addr2) || instruction::NOT(temp, temp);
  }
  else{
    //one of the args is float
    TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
    TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
    
    if(Types.isIntegerTy(t1)){
      //convert first arg to float
      std::string temp2 = "%"+codeCounters.newTEMP();
      code = code || instruction::FLOAT(temp2, addr1);
      addr1 = temp2;
    }else if(Types.isIntegerTy(t2)){
      //convert second arg to float
      std::string temp2 = "%"+codeCounters.newTEMP();
      code = code || instruction::FLOAT(temp2, addr2);
      addr2 = temp2;
    }

    //Generate code for the ops
    if(ctx->EQ()) code = code || instruction::FEQ(temp,addr1,addr2);
    else if (ctx->NEQ())
      code = code || instruction::FEQ(temp, addr1, addr2) || instruction::NOT(temp, temp);
    else if (ctx->L())
      code = code || instruction::FLT(temp, addr1, addr2);
    else if (ctx->LE())
      code = code || instruction::FLE(temp, addr1, addr2);
    else if (ctx->G())
      code = code || instruction::FLE(temp, addr1, addr2) || instruction::NOT(temp,temp);
    else // (ctx->GEQ())
      code = code || instruction::FLT(temp, addr1, addr2) || instruction::NOT(temp, temp);
   }


  /* ---------OLD CODE--------------
  code = code || instruction::EQ(temp, addr1, addr2);

  */
  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}


antlrcpp::Any CodeGenVisitor::visitValue(AslParser::ValueContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  std::string temp = "%"+codeCounters.newTEMP();

  if(ctx->INTVAL()){
    code = instruction::ILOAD(temp, ctx->getText());
  }else if(ctx->FLOATVAL()){
    code = instruction::FLOAD(temp, ctx->getText());
  }else if(ctx->BOOLVAL()){
    if(ctx->getText() == "true"){
      code = instruction::ILOAD(temp, "1");
    }else{
      code = instruction::ILOAD(temp, "0");
    }
  }else{ //charval
    code = instruction::CHLOAD(temp, ctx->getText());
  }
  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitExprIdent(AslParser::ExprIdentContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs && codAts = visit(ctx->ident());
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitParenthesis(AslParser::ParenthesisContext *ctx){
  DEBUG_ENTER();
  CodeAttribs && codAts = visit(ctx->expr());
  DEBUG_EXIT();
  return codAts;
}


antlrcpp::Any CodeGenVisitor::visitIdent(AslParser::IdentContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs codAts(ctx->ID()->getText(), "", instructionList());
  DEBUG_EXIT();
  return codAts;
}


// Getters for the necessary tree node atributes:
//   Scope and Type
SymTable::ScopeId CodeGenVisitor::getScopeDecor(antlr4::ParserRuleContext *ctx) const {
  return Decorations.getScope(ctx);
}
TypesMgr::TypeId CodeGenVisitor::getTypeDecor(antlr4::ParserRuleContext *ctx) const {
  return Decorations.getType(ctx);
}


// Constructors of the class CodeAttribs:
//
CodeGenVisitor::CodeAttribs::CodeAttribs(const std::string & addr,
                                         const std::string & offs,
                                         instructionList & code) :
  addr{addr}, offs{offs}, code{code} {
}

CodeGenVisitor::CodeAttribs::CodeAttribs(const std::string & addr,
                                         const std::string & offs,
                                         instructionList && code) :
  addr{addr}, offs{offs}, code{code} {
}
