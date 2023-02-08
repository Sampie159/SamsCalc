#include "parser.h"
#include "pile.h"
#include <stdlib.h>

double solveOperation(Operation *op) {
  double result;
  switch (op->operation) {
  case ADD:
    result = op->arg1 + op->arg2;
    free(op);
    return result;
    break;
  case SUB:
    result = op->arg1 - op->arg2;
    free(op);
    return result;
    break;
  case MUL:
    result = op->arg1 * op->arg2;
    free(op);
    return result;
    break;
  case DIV:
    result = op->arg1 / op->arg2;
    free(op);
    return result;
    break;
  default:
    return 0;
    break;
  }
}

inline double solveCurrentNode(PileOperations *po) {
  double result = solveOperation(po->op);
  free(po);
  return result;
}

double solvePileOperations(PileOperations *po) {
  if (po->next == NULL) {
    return solveCurrentNode(po);
  }
  po->op->arg2 = solvePileOperations(po->next);
  return solveCurrentNode(po);
}
