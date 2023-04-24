
// Generated from Asl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  AslLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, ASSIGN = 4, PLUS = 5, SUB = 6, MUL = 7, 
    DIV = 8, MOD = 9, VAR = 10, ARRAY = 11, INT = 12, FLOAT = 13, CHAR = 14, 
    BOOL = 15, EQ = 16, NEQ = 17, G = 18, GE = 19, L = 20, LE = 21, AND = 22, 
    NOT = 23, OR = 24, INTVAL = 25, FLOATVAL = 26, BOOLVAL = 27, CHARVAL = 28, 
    IF = 29, THEN = 30, ELSE = 31, ENDIF = 32, FUNC = 33, ENDFUNC = 34, 
    READ = 35, WRITE = 36, WHILE = 37, DO = 38, ENDWHILE = 39, RETURN = 40, 
    ID = 41, STRING = 42, COMMENT = 43, WS = 44, LPAR = 45, RPAR = 46, SEMICOLON = 47, 
    COLON = 48, COMMA = 49
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

