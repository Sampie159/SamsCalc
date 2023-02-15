#ifndef PARSER_H_
#define PARSER_H_

#include "tree.h"
#include <stddef.h>

typedef enum _TokenKind {
  FIM = 0,
  ADD = '+',
  SUB = '-',
  MUL = '*',
  DIV = '/',
  EXP_BEGIN = '(',
  EXP_END = ')',
  WHITESPACE = ' ',
  NUMBER
} TokenKind;

typedef struct _Token {
  TokenKind kind;
  const char *text;
  size_t textLen;
} Token;

TreeOperations *beginParse(char *);

#endif // PARSER_H_
