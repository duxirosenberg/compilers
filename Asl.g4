//////////////////////////////////////////////////////////////////////
//
//    Asl - Another simple language (grammar)
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

grammar Asl;

//////////////////////////////////////////////////
/// Parser Rules
//////////////////////////////////////////////////

// A program is a list of functions
program : function+ EOF
        ;

// A function has a name, a list of parameters and a list of statements
function
        : FUNC ID '(' parameters ')' (COLON basic_type)? declarations statements ENDFUNC
        ;

parameters
        : (ID COLON type (COMMA ID COLON type)*)?
        ;

declarations
        : (variable_decl)*
        ;

variable_decl
        : VAR ID (COMMA ID)* COLON type 
        ;

//chkpt1 new types declared, had to change visitType in SymbolsVisitor

type
        : basic_type
        | array_type
        ;

basic_type    
        : INT
        | FLOAT
        | CHAR
        | BOOL
        ;

array_type
        : ARRAY '[' INTVAL ']' 'of' basic_type
        ;

statements
        : (statement)*
        ;

// The different types of instructions
statement
          // Assignment
        : left_expr ASSIGN expr ';'                             # assignStmt
          // if-then-else statement (else is optional)
        | IF expr THEN statements (ELSE statements)? ENDIF      # ifStmt
        //whileloop
        | WHILE expr DO statements ENDWHILE                     #whileStmt
          // A function/procedure call has a list of arguments in parenthesis (possibly empty)
        | ident '(' (expr (COMMA expr)*)? ')' ';'               #procCall
        //Return
        | RETURN expr? ';'                                      #returnStmt
          // Read a variable
        | READ left_expr ';'                                    # readStmt
          // Write an expression
        | WRITE expr ';'                                        # writeExpr
          // Write a string
        | WRITE STRING ';'                                      # writeString
        ;

// Grammar for left expressions (l-values in C++)
left_expr
        : ident 
        | ident '[' expr ']'
        ;

// Grammar for expressions with boolean, relational and aritmetic operators
// Grammar for expressions with boolean, relational and aritmetic operators
expr    : expr op=FAC                         # factorial
        | expr op=EXP expr                    # exponential
        | LPAR expr RPAR                      # parenthesis
        | ident '[' expr ']'                  # arrayAccess
        | ident '(' (expr (COMMA expr)*)? ')' # functionCall
        | op= (NOT|PLUS|SUB) expr             # unary
        | expr op=(MUL|DIV|MOD) expr          # arithmetic
        | expr op=(PLUS|SUB) expr             # arithmetic
        | expr op=(EQ|NEQ|G|GE|L|LE) expr     # relational
        | expr op=AND expr                    # logical
        | expr op=OR expr                     # logical
        | (INTVAL|FLOATVAL|BOOLVAL|CHARVAL)   # value
        | ident                               # exprIdent
        ;

// Identifiers
ident   : ID
        ;

//////////////////////////////////////////////////
/// Lexer Rules
//////////////////////////////////////////////////

EXP       : '**';
ASSIGN    : '=' ;
PLUS      : '+' ;
SUB       : '-' ;
MUL       : '*';
DIV       : '/';
MOD       : '%';
FAC       : '!';

VAR       : 'var';
ARRAY     : 'array';
INT       : 'int';
//NEW
FLOAT     : 'float';
CHAR      : 'char';
BOOL      : 'bool';

//relational
EQ        : '==';
NEQ       : '!=';
G         : '>';
GE        : '>=';
L         : '<';
LE        : '<=';

//logical
AND       : 'and';
NOT       : 'not';
OR        : 'or';


IF        : 'if' ;
THEN      : 'then' ;
ELSE      : 'else' ;
ENDIF     : 'endif' ;
FUNC      : 'func' ;
ENDFUNC   : 'endfunc' ;
READ      : 'read' ;
WRITE     : 'write' ;
WHILE     : 'while' ;
DO        : 'do';
ENDWHILE  : 'endwhile';
RETURN    : 'return';

LPAR : '(' ;
RPAR : ')' ;
SEMICOLON : ';' ;
COLON : ':';
COMMA : ',';

INTVAL    : ('0'..'9')+ ;
//NEW
FLOATVAL  : ('0'..'9')+ '.' ('0'..'9')+ ;
BOOLVAL   : ('true'|'false') ;
CHARVAL   : '\'' ( ESC_SEQ | ~('\\'|'\'')) '\'' ;


ID        : ('a'..'z'|'A'..'Z') ('a'..'z'|'A'..'Z'|'_'|'0'..'9')* ;



// Strings (in quotes) with escape sequences
STRING    : '"' ( ESC_SEQ | ~('\\'|'"') )* '"' ;

fragment
ESC_SEQ   : '\\' ('b'|'t'|'n'|'f'|'r'|'"'|'\''|'\\') ;

// Comments (inline C++-style)
COMMENT   : '//' ~('\n'|'\r')* '\r'? '\n' -> skip ;

// White spaces
WS        : (' '|'\t'|'\r'|'\n')+ -> skip ;
// Alternative description
// WS        : [ \t\r\n]+ -> skip ;

