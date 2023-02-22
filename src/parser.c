#include "parser.h"
#include "token.h"
#include "tree.h"
#include <ctype.h>
#include <string.h>

// TODO: Parse through the input string and generate a list of tokens
// TODO: Generate a pile of operations from these tokens

TreeOperations *beginParse(char *buffer) {
  TreeOperations *to = newTree();
  char *aux = "";
  TokenList *tl = newTokenList();

  for (int i = 0; i < strlen(buffer); i++) {
    if (isdigit(buffer[i + 1]))
      aux += buffer[i];
    else {
      aux += buffer[i] + buffer[i + 1];
      Token *t = newToken(NUMBER, aux);
      tl->token = t;
    }
  }
  return to;
}
