#include "calculator.h"
#include "parser.h"
#include "tree.h"
#include <stdlib.h>

typedef double (*operationFunc)(double, double);

static inline double add(double a, double b) { return a + b; }
static inline double sub(double a, double b) { return a - b; }
static inline double mul(double a, double b) { return a * b; }
static inline double divide(double a, double b) { return a / b; }

static inline double operation(operationFunc func, Operation *op) {
  double result = func(op->arg1, op->arg2);
  free(op);
  return result;
}

static inline double solveOperation(Operation *op) {
  switch (op->operation) {
  case ADD:
    return operation(add, op);
  case SUB:
    return operation(sub, op);
  case MUL:
    return operation(mul, op);
  case DIV:
    return operation(divide, op);
  default:
    return 0;
  }
}

double solveTreeOperations(TreeOperations *po) {
  if (po->leftNode != NULL)
    po->op->arg1 = solveTreeOperations(po->leftNode);

  if (po->rightNode != NULL)
    po->op->arg2 = solveTreeOperations(po->rightNode);

  double result = solveOperation(po->op);
  free(po);
  return result;
}
