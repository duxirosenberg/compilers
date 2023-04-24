//////////////////////////////////////////////////////////////////////
//
//    TypeCheckVisitor - Walk the parser tree to do the semantic
//                       typecheck for the Asl programming language
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

#include "TypeCheckVisitor.h"
#include "antlr4-runtime.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/SemErrors.h"

#include <iostream>
#include <string>

// uncomment the following line to enable debugging messages with DEBUG*
// #define DEBUG_BUILD
#include "../common/debug.h"

// using namespace std;


// Constructor
TypeCheckVisitor::TypeCheckVisitor(TypesMgr       & Types,
                                   SymTable       & Symbols,
                                   TreeDecoration & Decorations,
                                   SemErrors      & Errors) :
  Types{Types},
  Symbols{Symbols},
  Decorations{Decorations},
  Errors{Errors} {
}

// Accessor/Mutator to the attribute currFunctionType
TypesMgr::TypeId TypeCheckVisitor::getCurrentFunctionTy() const {
  return currFunctionType;
}

void TypeCheckVisitor::setCurrentFunctionTy(TypesMgr::TypeId type) {
  currFunctionType = type;
}

// Methods to visit each kind of node:
//
antlrcpp::Any TypeCheckVisitor::visitProgram(AslParser::ProgramContext *ctx) {
  DEBUG_ENTER();
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  for (auto ctxFunc : ctx->function()) { 
    visit(ctxFunc);
  }
  if (Symbols.noMainProperlyDeclared())
    Errors.noMainProperlyDeclared(ctx);
  Symbols.popScope();
  Errors.print();
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitFunction(AslParser::FunctionContext *ctx) {
  DEBUG_ENTER();

  //set function type
  std::vector<TypesMgr::TypeId> paramTypes;
  TypesMgr::TypeId t1 = Types.createVoidTy();
  if (ctx->basic_type()) {
    t1 = getTypeDecor(ctx->basic_type());
  }  
  TypesMgr::TypeId t2 = Types.createFunctionTy(paramTypes,t1);
  setCurrentFunctionTy(t2);


  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  // Symbols.print();
  visit(ctx->statements());
  Symbols.popScope();
  DEBUG_EXIT();
  return 0;
}

// antlrcpp::Any TypeCheckVisitor::visitDeclarations(AslParser::DeclarationsContext *ctx) {
//   DEBUG_ENTER();
//   antlrcpp::Any r = visitChildren(ctx);
//   DEBUG_EXIT();
//   return r;
// }

// antlrcpp::Any TypeCheckVisitor::visitVariable_decl(AslParser::Variable_declContext *ctx) {
//   DEBUG_ENTER();
//   antlrcpp::Any r = visitChildren(ctx);
//   DEBUG_EXIT();
//   return r;
// }

// antlrcpp::Any TypeCheckVisitor::visitType(AslParser::TypeContext *ctx) {
//   DEBUG_ENTER();
//   antlrcpp::Any r = visitChildren(ctx);
//   DEBUG_EXIT();
//   return r;
// }

antlrcpp::Any TypeCheckVisitor::visitStatements(AslParser::StatementsContext *ctx) {
  DEBUG_ENTER();
  visitChildren(ctx);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitAssignStmt(AslParser::AssignStmtContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->left_expr());
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->left_expr());
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) and
      (not Types.copyableTypes(t1, t2)))
    Errors.incompatibleAssignment(ctx->ASSIGN());
  if ((not Types.isErrorTy(t1)) and (not getIsLValueDecor(ctx->left_expr())))
    Errors.nonReferenceableLeftExpr(ctx->left_expr());
  DEBUG_EXIT();
  return 0;
}


antlrcpp::Any TypeCheckVisitor::visitIfStmt(AslParser::IfStmtContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1)))
    Errors.booleanRequired(ctx);
  visit(ctx->statements(0));
  if (ctx->ELSE()) {
    visit(ctx->statements(1));
  }
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitProcCall(AslParser::ProcCallContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->ident());
  //visit every parameter
  for (auto expr : ctx->expr()) {
    visit(expr);
  }
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());

  if (not Types.isFunctionTy(t1) and not Types.isErrorTy(t1)) {
    //Error1: not a callable function
    Errors.isNotCallable(ctx->ident());
  }else if (not Types.isErrorTy(t1)){
    std::vector<TypesMgr::TypeId> params = Types.getFuncParamsTypes(t1);
    std::vector<AslParser::ExprContext *> args = ctx->expr();
    if (params.size() != args.size()) {
      //Error2: number of parameters mismatch
      Errors.numberOfParameters(ctx->ident());
    }else{
      for (unsigned int i = 0; i < params.size(); ++i) {
        visit(args[i]);
        TypesMgr::TypeId t2 = getTypeDecor(args[i]);
        if ((not Types.isErrorTy(t2)) and (not Types.copyableTypes(params[i], t2)))
          //Error3: incompatible parameter
          Errors.incompatibleParameter(ctx->expr(i), i+1, ctx);
      }
    }
  }
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitReadStmt(AslParser::ReadStmtContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->left_expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->left_expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isPrimitiveTy(t1)) and
      (not Types.isFunctionTy(t1)))
    Errors.readWriteRequireBasic(ctx);
  if ((not Types.isErrorTy(t1)) and (not getIsLValueDecor(ctx->left_expr())))
    Errors.nonReferenceableExpression(ctx);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitWriteExpr(AslParser::WriteExprContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isPrimitiveTy(t1)))
    Errors.readWriteRequireBasic(ctx);
  DEBUG_EXIT();
  return 0;
}

// antlrcpp::Any TypeCheckVisitor::visitWriteString(AslParser::WriteStringContext *ctx) {
//   DEBUG_ENTER();
//   antlrcpp::Any r = visitChildren(ctx);
//   DEBUG_EXIT();
//   return r;
// }

antlrcpp::Any TypeCheckVisitor::visitLeft_expr(AslParser::Left_exprContext *ctx) {
  DEBUG_ENTER();

  visit(ctx->ident());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  bool b = getIsLValueDecor(ctx->ident());


  if(ctx->expr()){
    //there is an expr ==> it is an array

    visit(ctx->expr());
    TypesMgr::TypeId t2 = getTypeDecor(ctx->expr());

    //does not work with if else hence use the following bool
    bool has_error = Types.isErrorTy(t1);

    //Error 1: t1 is an erroneous type/not an array 
    if(not Types.isErrorTy(t1) and not Types.isArrayTy(t1)){
      Errors.nonArrayInArrayAccess(ctx);
      b = false;
      has_error= true;
      t1 = Types.createErrorTy();
    }
    //Error 2: indext is not an integer
    if (not Types.isErrorTy(t2) and not Types.isIntegerTy(t2)){
      Errors.nonIntegerIndexInArrayAccess(ctx->expr());
     }
    //no Error: 
    if(not has_error){
      t1 = Types.getArrayElemType(t1);
    }
  }


  putTypeDecor(ctx, t1);
  putIsLValueDecor(ctx, b);
  

  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitArithmetic(AslParser::ArithmeticContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr(0));
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  visit(ctx->expr(1));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  if (((not Types.isErrorTy(t1)) and (not Types.isNumericTy(t1))) or
      ((not Types.isErrorTy(t2)) and (not Types.isNumericTy(t2))))
    Errors.incompatibleOperator(ctx->op);
  
  //type coercion
  if (Types.isFloatTy(t1) or Types.isFloatTy(t2)) {
    TypesMgr::TypeId t = Types.createFloatTy();
    putTypeDecor(ctx, t);
  }
  else {
    TypesMgr::TypeId t = Types.createIntegerTy();
    putTypeDecor(ctx, t);
  }

  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitRelational(AslParser::RelationalContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr(0));
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  visit(ctx->expr(1));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  std::string oper = ctx->op->getText();
  if ((not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) and
      (not Types.comparableTypes(t1, t2, oper)))
    Errors.incompatibleOperator(ctx->op);
  TypesMgr::TypeId t = Types.createBooleanTy();
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitValue(AslParser::ValueContext *ctx) {
  DEBUG_ENTER();  
  TypesMgr::TypeId t = Types.createErrorTy();
  if(ctx->INTVAL()) {
    t = Types.createIntegerTy();
  }
  else if(ctx->FLOATVAL()) {
    t = Types.createFloatTy();
  }
  else if(ctx->BOOLVAL()) {
    t = Types.createBooleanTy();
  }
  else if(ctx->CHARVAL()) {
    t = Types.createCharacterTy();
  }
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitExprIdent(AslParser::ExprIdentContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->ident());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  putTypeDecor(ctx, t1);
  bool b = getIsLValueDecor(ctx->ident());
  putIsLValueDecor(ctx, b);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitIdent(AslParser::IdentContext *ctx) {
  DEBUG_ENTER();
  std::string ident = ctx->getText();
  if (Symbols.findInStack(ident) == -1) {
    Errors.undeclaredIdent(ctx->ID());
    TypesMgr::TypeId te = Types.createErrorTy();
    putTypeDecor(ctx, te);
    putIsLValueDecor(ctx, true);
  }
  else {
    TypesMgr::TypeId t1 = Symbols.getType(ident);
    putTypeDecor(ctx, t1);
    if (Symbols.isFunctionClass(ident))
      putIsLValueDecor(ctx, false);
    else
      putIsLValueDecor(ctx, true);
  }
  DEBUG_EXIT();
  return 0;
}


antlrcpp::Any TypeCheckVisitor::visitParenthesis(AslParser::ParenthesisContext *ctx){
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  putTypeDecor(ctx, t1);
  bool b = getIsLValueDecor(ctx->expr());
  putIsLValueDecor(ctx, b);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitUnary(AslParser::UnaryContext *ctx){
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());

  //differntiatie between NOT and SUB/PLUS
  if(ctx->NOT()){
    if(not Types.isErrorTy(t1) and not Types.isBooleanTy(t1)){
      //print t1 type error
      Errors.incompatibleOperator(ctx->op);
    }
    else{
      t1 = Types.createBooleanTy();
    }
  }
  else{
    if(not Types.isErrorTy(t1) and not Types.isNumericTy(t1)){
      Errors.incompatibleOperator(ctx->op);
    }
    else{
      if(Types.isFloatTy(t1)){
        t1 = Types.createFloatTy();
      }
      else{
        t1 = Types.createIntegerTy();
      }
    }
  }
  
  putTypeDecor(ctx, t1);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}


antlrcpp::Any TypeCheckVisitor::visitLogical(AslParser::LogicalContext *ctx){
  DEBUG_ENTER();
  visit(ctx->expr(0));
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  visit(ctx->expr(1));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  if(((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1))) or
     ((not Types.isErrorTy(t2)) and (not Types.isBooleanTy(t2))))
    Errors.incompatibleOperator(ctx->op);
  TypesMgr::TypeId t = Types.createBooleanTy();
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitWhileStmt(AslParser::WhileStmtContext *ctx){
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1)))
    Errors.booleanRequired(ctx);
  visit(ctx->statements());
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitArrayAccess(AslParser::ArrayAccessContext *ctx){
  DEBUG_ENTER();
  visit(ctx->ident());
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr());
  TypesMgr::TypeId t3 = Types.createErrorTy();
  
  if (not Types.isErrorTy(t1)){
    if(not Types.isArrayTy(t1)){
      Errors.nonArrayInArrayAccess(ctx);
    }
    else{
      t3 = Types.getArrayElemType(t1);
    }
  }

  if (not Types.isErrorTy(t2) and not Types.isIntegerTy(t2)){
    Errors.nonIntegerIndexInArrayAccess(ctx->expr());
  }

  putTypeDecor(ctx, t3);
  putIsLValueDecor(ctx, true);  
  
  DEBUG_EXIT();
  return 0;
}


antlrcpp::Any TypeCheckVisitor::visitFunctionCall(AslParser::FunctionCallContext *ctx){
  DEBUG_ENTER();
  visit(ctx->ident());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  TypesMgr::TypeId t2 = Types.createErrorTy();

  
  //Error1: is it not a function
  if (not Types.isErrorTy(t1) and not Types.isFunctionTy(t1)){
    Errors.isNotCallable(ctx->ident());
    t2 = Types.createErrorTy();
  }else if(Types.isFunctionTy(t1)){
    t2 = Types.getFuncReturnType(t1);
    //Error2: function return value is not usable
    if(Types.isVoidFunction(t1)){
      Errors.isNotFunction(ctx->ident());
      t2 = Types.createErrorTy();
    };
    
    //error3: wrong number of parameters
    if((ctx->expr().size() != Types.getNumOfParameters(t1))){
        Errors.numberOfParameters(ctx->ident());
    } else{
      std::vector<TypesMgr::TypeId> parameters = Types.getFuncParamsTypes(t1);
      int len = parameters.size();
      for(int i = 0; i < len; i++){
        visit(ctx->expr(i));
        TypesMgr::TypeId t_temp = getTypeDecor(ctx->expr(i));

        if(not Types.equalTypes(t_temp,parameters[i]) and not Types.isErrorTy(t_temp) \
          and Types.isFloatTy(parameters[i]) and not Types.isIntegerTy(t_temp)){
          Errors.incompatibleParameter(ctx->expr(i),i+1,ctx);
        }
      }
    }

  }
  
  putTypeDecor(ctx, t2);
  putIsLValueDecor(ctx, false);  
  DEBUG_EXIT();
  return 0;
}


antlrcpp::Any TypeCheckVisitor::visitReturnStmt(AslParser::ReturnStmtContext *ctx){
  DEBUG_ENTER();
  TypesMgr::TypeId t1 = getCurrentFunctionTy();
  if (ctx->expr()){
    visit(ctx->expr());
    TypesMgr::TypeId t2 = getTypeDecor(ctx->expr());
    TypesMgr::TypeId t3 = Types.getFuncReturnType(t1);; 
  
    if(not Types.equalTypes(t2,t3) and not Types.isErrorTy(t2) and not Types.isErrorTy(t3)){
      if(not(Types.isFloatTy(t3) and Types.isIntegerTy(t2))){
        Errors.incompatibleReturn(ctx->RETURN());
      }
    }
  }
  else{
    if(not Types.isVoidFunction(t1)){
      Errors.incompatibleReturn(ctx->RETURN());
    }
  }
  
  DEBUG_EXIT();
  return 0;
}









// Getters for the necessary tree node atributes:
//   Scope, Type ans IsLValue
SymTable::ScopeId TypeCheckVisitor::getScopeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getScope(ctx);
}
TypesMgr::TypeId TypeCheckVisitor::getTypeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getType(ctx);
}
bool TypeCheckVisitor::getIsLValueDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getIsLValue(ctx);
}

// Setters for the necessary tree node attributes:
//   Scope, Type ans IsLValue
void TypeCheckVisitor::putScopeDecor(antlr4::ParserRuleContext *ctx, SymTable::ScopeId s) {
  Decorations.putScope(ctx, s);
}
void TypeCheckVisitor::putTypeDecor(antlr4::ParserRuleContext *ctx, TypesMgr::TypeId t) {
  Decorations.putType(ctx, t);
}
void TypeCheckVisitor::putIsLValueDecor(antlr4::ParserRuleContext *ctx, bool b) {
  Decorations.putIsLValue(ctx, b);
}
