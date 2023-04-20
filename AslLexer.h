
// Generated from Asl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  AslLexer : public antlr4::Lexer {
public:
  enum {
    ASSIGN = 1, PLUS = 2, SUB = 3, MUL = 4, DIV = 5, MOD = 6, VAR = 7, INT = 8, 
    FLOAT = 9, CHAR = 10, BOOL = 11, EQ = 12, NEQ = 13, G = 14, GE = 15, 
    L = 16, LE = 17, AND = 18, NOT = 19, OR = 20, INTVAL = 21, FLOATVAL = 22, 
    BOOLVAL = 23, CHARVAL = 24, IF = 25, THEN = 26, ELSE = 27, ENDIF = 28, 
    FUNC = 29, ENDFUNC = 30, READ = 31, WRITE = 32, WHILE = 33, DO = 34, 
    ENDWHILE = 35, RETURN = 36, ID = 37, STRING = 38, COMMENT = 39, WS = 40, 
    LPAR = 41, RPAR = 42, SEMICOLON = 43, COLON = 44, COMMA = 45
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

