
// Generated from Asl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  AslLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, ASSIGN = 3, PLUS = 4, SUB = 5, MUL = 6, DIV = 7, 
    MOD = 8, VAR = 9, INT = 10, FLOAT = 11, CHAR = 12, BOOL = 13, EQ = 14, 
    NEQ = 15, G = 16, GE = 17, L = 18, LE = 19, AND = 20, NOT = 21, OR = 22, 
    INTVAL = 23, FLOATVAL = 24, BOOLVAL = 25, CHARVAL = 26, IF = 27, THEN = 28, 
    ELSE = 29, ENDIF = 30, FUNC = 31, ENDFUNC = 32, READ = 33, WRITE = 34, 
    WHILE = 35, DO = 36, ENDWHILE = 37, RETURN = 38, ID = 39, STRING = 40, 
    COMMENT = 41, WS = 42, LPAR = 43, RPAR = 44, SEMICOLON = 45, COLON = 46, 
    COMMA = 47
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

