
// Generated from Asl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  AslLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, EXP = 4, ASSIGN = 5, PLUS = 6, SUB = 7, 
    MUL = 8, DIV = 9, MOD = 10, FAC = 11, VAR = 12, ARRAY = 13, INT = 14, 
    FLOAT = 15, CHAR = 16, BOOL = 17, EQ = 18, NEQ = 19, G = 20, GE = 21, 
    L = 22, LE = 23, AND = 24, NOT = 25, OR = 26, IF = 27, THEN = 28, ELSE = 29, 
    ENDIF = 30, FUNC = 31, ENDFUNC = 32, READ = 33, WRITE = 34, WHILE = 35, 
    DO = 36, ENDWHILE = 37, RETURN = 38, LPAR = 39, RPAR = 40, SEMICOLON = 41, 
    COLON = 42, COMMA = 43, INTVAL = 44, FLOATVAL = 45, BOOLVAL = 46, CHARVAL = 47, 
    ID = 48, STRING = 49, COMMENT = 50, WS = 51
  };

  AslLexer(antlr4::CharStream *input);
  ~AslLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

