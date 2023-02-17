#ifndef TOKEN_H_
#define TOKEN_H_

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

#endif // TOKEN_H_