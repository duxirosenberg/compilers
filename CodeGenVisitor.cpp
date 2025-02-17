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
    if(isArray){
      tid = Types.getArrayElemType(tid);
    }
    lparams.push_back(var(id, Types.to_string(tid), isArray));
  }

  DEBUG_EXIT();
  return lparams;
}


antlrcpp::Any CodeGenVisitor::visitReturnStmt(AslParser::ReturnStmtContext *ctx){
  DEBUG_ENTER();
  instructionList code;
  if(ctx->expr()){
    CodeAttribs     && codAtsE = visit(ctx->expr());
    std::string           addr = codAtsE.addr;
    // std::string           offs = codAtsE.offs;
    instructionList &     code1 = codAtsE.code;
    code = code1 || instruction::LOAD("_result",addr);
  }
  code = code || instruction::RETURN();
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
    if(Types.isArrayTy(t1)){
      t1 = Types.getArrayElemType(t1);
    }
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
  std::string           offs1 = codAtsE1.offs;
  instructionList &     code1 = codAtsE1.code;
  TypesMgr::TypeId tid1 = getTypeDecor(ctx->left_expr());
  
  CodeAttribs     && codAtsE2 = visit(ctx->expr());
  std::string           addr2 = codAtsE2.addr;
  //std::string           offs2 = codAtsE2.offs;
  instructionList &     code2 = codAtsE2.code;
  TypesMgr::TypeId tid2 = getTypeDecor(ctx->expr());
  
  code = code1 || code2;     //before arrays: || instruction::LOAD(addr1, addr2);

  
  //NEW CODE for arrays
  if(Types.isArrayTy(tid1) and Types.isArrayTy(tid2)) {
    //
    if(not Symbols.isLocalVarClass(addr1)){
      std::string tmp1 = "%"+codeCounters.newTEMP();
      code = code || instruction::LOAD(tmp1, addr1);
      addr1 = tmp1;
    }
    if(not Symbols.isLocalVarClass(addr2)){
      std::string tmp2 = "%"+codeCounters.newTEMP();
      code = code || instruction::LOAD(tmp2, addr2);
      addr2 = tmp2;
    }
    std::string labelWhile = "while"+codeCounters.newLabelWHILE();
    std::string labelEndWhile = "end"+labelWhile;
    
    std::string number_elements = std::to_string(Types.getArraySize(tid1)-1);
    std::string offset = "%"+codeCounters.newTEMP();
    std::string element = "%"+codeCounters.newTEMP();
    std::string condition = "%"+codeCounters.newTEMP();
    std::string zero = "%"+codeCounters.newTEMP();
    std::string one = "%"+codeCounters.newTEMP();

    code = code ||
           instruction::ILOAD(offset, number_elements) ||
           instruction::ILOAD(zero, "0") ||
           instruction::ILOAD(one, "1") ||
           instruction::LABEL(labelWhile) ||
           instruction::LE(condition,zero,offset) ||
           instruction::FJUMP(condition,labelEndWhile) ||
           instruction::LOADX(element,addr2,offset) ||
           instruction::XLOAD(addr1,offset,element) ||
           instruction::SUB(offset,offset,one) ||
           instruction::UJUMP(labelWhile) ||
           instruction::LABEL(labelEndWhile);

  }
  else{
    //not an array
    if (Types.isFloatTy(tid1) && Types.isIntegerTy(tid2)){
            //type coercion from int to float
        std::string tmp = "%"+codeCounters.newTEMP();
        code = code || instruction::FLOAT(tmp, addr2);
        addr2 = tmp;
      }

    if(ctx->left_expr()->expr()){
      //left expr is array access a[i]
      if(Symbols.isLocalVarClass(addr1)){
        //local array
        code = code || instruction::XLOAD(addr1, offs1, addr2);
      }else{ //parameter
        std::string temp2 = "%"+codeCounters.newTEMP();
        code = code || instruction::LOAD(temp2, addr1)
                    || instruction::XLOAD(temp2, offs1,addr2);
      }
    }else{
      //left expr is a variable
      code = code || instruction::LOAD(addr1, addr2);
    }
  }

  
  
  
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

antlrcpp::Any CodeGenVisitor::visitExponential(AslParser::ExponentialContext *ctx){
  DEBUG_ENTER();
  instructionList code;

  CodeAttribs     && codAtsE1 = visit(ctx->expr(0));
  std::string          addr1 = codAtsE1.addr;
  instructionList &    code1 = codAtsE1.code;

  CodeAttribs     && codAtsE2 = visit(ctx->expr(1));
  std::string          addr2 = codAtsE2.addr;
  instructionList &    code2 = codAtsE2.code;



  std::string res = "%"+codeCounters.newTEMP();
  std::string base = "%"+codeCounters.newTEMP();
  std::string exp = "%"+codeCounters.newTEMP();

  code = code1 || code2;
  code = code || instruction::ILOAD(exp, addr2);
  
  if(Types.isIntegerTy(getTypeDecor(ctx->expr(0)))){
    std::string temp = "%"+codeCounters.newTEMP();
    code = code || instruction::FLOAT(base,addr1);
  }else{ //float base
    code = code || instruction::FLOAD(base,addr1);
  }

  //implement while loop
  std::string iter = "%"+codeCounters.newTEMP();
  std::string test = "%"+codeCounters.newTEMP();
  std::string one = "%"+codeCounters.newTEMP();

  std::string label = "while"+codeCounters.newLabelWHILE()+"_exponential"; 
  std::string labelEndWhile = "end"+label;
  code = code || instruction::ILOAD(iter,exp) ||
            instruction::ILOAD(one,"1") ||
            instruction::FLOAT(res, one) ||
            instruction::LABEL(label) ||
            instruction::LE(test,one,iter) ||
            instruction::FJUMP(test,labelEndWhile) ||
            instruction::FMUL(res,res,base) ||
            instruction::SUB(iter,iter,one)  ||
            instruction::UJUMP(label) ||
            instruction::LABEL(labelEndWhile);

  CodeAttribs codAts(res, "", code);
  DEBUG_EXIT();
  return codAts;
}









antlrcpp::Any CodeGenVisitor::visitFactorial(AslParser::FactorialContext *ctx){
  DEBUG_ENTER();
  instructionList code;
  CodeAttribs     && codAtsE = visit(ctx->expr());
  std::string          addr1 = codAtsE.addr;
  instructionList &    code1 = codAtsE.code;

  std::string start = "%"+codeCounters.newTEMP();
  std::string res = "%"+codeCounters.newTEMP();
  std::string test = "%"+codeCounters.newTEMP();
  std::string one = "%"+codeCounters.newTEMP();
  std::string zero = "%"+codeCounters.newTEMP();

  code = code1 || instruction::ILOAD(res, "1");
  code = code || instruction::ILOAD(one, "1");
  code = code || instruction::ILOAD(zero, "0");
  code = code || instruction::LOAD(start, addr1);



  std::string labelwhile = "while"+codeCounters.newLabelWHILE() + "_factorial";
  std::string labelEndWhile = "end"+labelwhile;
  
  //if n>0 jump to while loop otherwise HALT and jump to endwhile
  code = code || instruction::LT(test,start,zero) || 
          instruction::FJUMP(test,labelwhile) ||
          instruction::LABEL("negative_operator") ||
          instruction::HALT(code::INVALID_INTEGER_OPERAND) ||
          instruction::UJUMP(labelEndWhile);

  
  code = code || instruction::LABEL(labelwhile) ||
         instruction::LE(test,one,start) || 
         instruction::FJUMP(test,labelEndWhile) ||
         instruction::MUL(res,res,start) || 
         instruction::SUB(start,start,one) ||
         instruction::UJUMP(labelwhile) || 
         instruction::LABEL(labelEndWhile);

  CodeAttribs codAts(res, "", code);

  DEBUG_EXIT();
  return codAts;
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

  if(ctx->ELSE()){
      instructionList && code3 = visit(ctx->statements(1)); //else code
      std::string labelElse = "else"+label;
      code = code1 || instruction::FJUMP(addr1, labelElse) ||
      code2 || instruction::UJUMP(labelEndIf) || instruction::LABEL(labelElse) ||
      code3 || instruction::LABEL(labelEndIf);
  }
  else{
      code = code1 || instruction::FJUMP(addr1, labelEndIf) ||
      code2 || instruction::LABEL(labelEndIf);
  }

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

  //return for non-void functions (some functions may not have return)
  if(not Types.isVoidFunction(type)){
    pushParams = pushParams || instruction::PUSH();
    popParams = popParams || instruction::POP();
  }

  for(size_t i = 0; i < (ctx->expr()).size(); i++){
    CodeAttribs && codeAtParameter = visit(ctx->expr(i));
    std::string addr_param = codeAtParameter.addr;
    instructionList & code_param = codeAtParameter.code;
    TypesMgr::TypeId tP = getTypeDecor(ctx->expr(i));

    code = code || code_param;
    std::string param_temp = addr_param;

    if(Types.isFloatTy(typesParams[i]) and Types.isIntegerTy(tP)){
      //type coercion from int to float
      param_temp = "%"+codeCounters.newTEMP();
      code = code || instruction::FLOAT(param_temp, addr_param);
    }
    else if(Types.isArrayTy(tP) && Symbols.isLocalVarClass(addr_param)){
      param_temp = "%"+codeCounters.newTEMP();
      code = code || instruction::ALOAD(param_temp, addr_param);
    }

    pushParams = pushParams || instruction::PUSH(param_temp);
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
    if(Types.isArrayTy(formal_type_param) && Symbols.isLocalVarClass(addr_param)){
      param_temp = "%"+codeCounters.newTEMP();
      code = code || instruction::ALOAD(param_temp,addr_param);
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
  std::string          offs1 = codAtsE.offs;
  instructionList &    code1 = codAtsE.code;
  instructionList &     code = code1;
  TypesMgr::TypeId tid1 = getTypeDecor(ctx->left_expr());

  std::string temp = addr1;
  bool && isArrayElement = ctx->left_expr()->expr();
  if(isArrayElement){
    temp = "%"+codeCounters.newTEMP();
  }

  if(Types.isFloatTy(tid1))
    code = code1 || instruction::READF(temp);
  else if (Types.isCharacterTy(tid1))
    code = code1 || instruction::READC(temp);
  else
    code = code1 || instruction::READI(temp);

  if (isArrayElement) {
    if(Symbols.isLocalVarClass(addr1)){
        //local array
        code = code || instruction::XLOAD(addr1, offs1, temp);
      }else{ //parameter
        std::string temp2 = "%"+codeCounters.newTEMP();
        code = code || instruction::LOAD(temp2, addr1)
                    || instruction::XLOAD(temp2, offs1,temp);
      }
    //code = code || instruction::XLOAD(addr1,offs1,temp);
  }
  DEBUG_EXIT();
  return code;
}


antlrcpp::Any CodeGenVisitor::visitWriteExpr(AslParser::WriteExprContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->expr());
  std::string         addr1 = codAt1.addr;
  // std::string         offs1 = codAt1.offs;
  instructionList &   code = codAt1.code;
  TypesMgr::TypeId tid1 = getTypeDecor(ctx->expr());
  
  if (Types.isFloatTy(tid1)) {
    code = code || instruction::WRITEF(addr1);
  } else if (Types.isCharacterTy(tid1)){
    code = code || instruction::WRITEC(addr1);
  } else {
    code = code || instruction::WRITEI(addr1);
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
  CodeAttribs && codAtIdent = visit(ctx->ident());
  std::string addrIdent = codAtIdent.addr;
  instructionList & codeIdent = codAtIdent.code;
  instructionList & code = codeIdent;
  std::string offs = "";

  if(ctx->expr()){ //array
    CodeAttribs && codAtExpr = visit(ctx->expr());
    std::string addrExpr = codAtExpr.addr;
    instructionList & codeExpr = codAtExpr.code;
    code = code || codeExpr;
    offs = addrExpr;
  }


  CodeAttribs codAts(addrIdent, offs, code);

  DEBUG_EXIT();
  return codAts;
}


antlrcpp::Any CodeGenVisitor::visitUnary(AslParser::UnaryContext *ctx){
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->expr());
  std::string         addr1 = codAt1.addr;
  instructionList &   code = codAt1.code;

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
  }else if (ctx->PLUS()){
    if(Types.isIntegerTy(tid1)){
      code = code || instruction::LOAD(temp, addr1);
    }else{
      code = code || instruction::FLOAD(temp, addr1);
    }  }

  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}



antlrcpp::Any CodeGenVisitor::visitArithmetic(AslParser::ArithmeticContext *ctx) {
  DEBUG_ENTER();

  CodeAttribs     && codAt1 = visit(ctx->expr(0));

  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;
  CodeAttribs     && codAt2 = visit(ctx->expr(1));

  std::string         addr2 = codAt2.addr;
  instructionList &   code2 = codAt2.code;
  instructionList &&   code = code1 || code2;

  std::string temp = "%"+codeCounters.newTEMP();


  if(Types.isIntegerTy(getTypeDecor(ctx))){

    
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
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  std::string temp = "%"+codeCounters.newTEMP();
  if((Types.isIntegerTy(t1) && Types.isIntegerTy(t2))
     or (Types.isCharacterTy(t1) && Types.isCharacterTy(t2))
     or (Types.isBooleanTy(t1) && Types.isBooleanTy(t2))
     ){
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
    
    if(Types.isIntegerTy(t1)){
      //convert first arg to float
      std::string temp2 = "%"+codeCounters.newTEMP();
      code = code || instruction::FLOAT(temp2, addr1);
      addr1 = temp2;
    }
    if(Types.isIntegerTy(t2)){
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
    std::string token = ctx->getText();
    code = instruction::CHLOAD(temp, token.substr(1,token.size()-2));
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

antlrcpp::Any CodeGenVisitor::visitArrayAccess(AslParser::ArrayAccessContext *ctx){
  DEBUG_ENTER();
  CodeAttribs && codAts = visit(ctx->ident());
  std::string addr = codAts.addr;
  instructionList & code = codAts.code;

  //get the index
  CodeAttribs && codAts2 = visit(ctx->expr());
  std::string addr2 = codAts2.addr;
  instructionList & code2 = codAts2.code;

  code = code || code2;
  std::string temp = "%"+codeCounters.newTEMP();

  if(Symbols.isLocalVarClass(addr)){
    //local array
    code = code || instruction::LOADX(temp, addr, addr2);
  }else{ //parameter
    std::string temp2 = "%"+codeCounters.newTEMP();
    code = code || instruction::LOAD(temp2, addr)
                || instruction::LOADX(temp, temp2,addr2);

  }
  
  DEBUG_EXIT();
  return CodeAttribs(temp, "", code);
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
