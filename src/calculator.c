#include "parser.h"
#include "tree.h"
#include <stdlib.h>

inline double solveOperation(Operation *op) {
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

static inline double solveCurrentNode(TreeOperations *po) {
  double result = solveOperation(po->op);
  free(po);
  return result;
}

double solveTreeOperations(TreeOperations *po) {
  if (po->leftNode == NULL && po->rightNode == NULL)
    return solveCurrentNode(po);

  if (po->leftNode != NULL)
    po->op->arg1 = solveTreeOperations(po->leftNode);

  if (po->rightNode != NULL)
    po->op->arg2 = solveTreeOperations(po->rightNode);

  return solveCurrentNode(po);
}
