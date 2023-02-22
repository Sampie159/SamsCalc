#include "token.h"
#include <stdlib.h>
#include <string.h>

Token *newToken(TokenKind tk, const char *tt) {
  Token *t = (Token *)malloc(sizeof(Token *));
  t->kind = tk;
  t->text = tt;
  t->textLen = strlen(t->text);

  return t;
}

TokenList *newTokenList() {
  TokenList *tl = (TokenList *)malloc(sizeof(TokenList *));
  tl->token = NULL;
  tl->next = NULL;
  return tl;
}
