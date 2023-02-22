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

typedef struct _TokenList {
  Token *token;
  struct _TokenList *next;
} TokenList;

Token *newToken(TokenKind, const char *);
TokenList *newTokenList();

#endif // TOKEN_H_
