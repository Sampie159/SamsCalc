#include "parser.h"
#include "tree.h"
#include <stdlib.h>
// TODO: Recieve a string of characters and generate a list of tokens

double solveOperation(Operation *op) {
  switch (op->operation) {
  case ADD:
    return op->arg1 + op->arg2;
    break;
  case SUB:
    return op->arg1 - op->arg2;
    break;
  case MUL:
    return op->arg1 * op->arg2;
    break;
  case DIV:
    return op->arg1 / op->arg2;
    break;
  default:
    return 0;
    break;
  }
}

double solveListOperations(ListOperations *lo) {
  if (lo->next->next == NULL) {
    lo->op->arg2 = solveOperation(lo->op);
    free(lo);
  }
  return solveListOperations(lo->next);
}
