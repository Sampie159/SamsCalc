#include "parser.h"
#include "tree.h"
#include <stdlib.h>

// TODO: Parse through the input string and generate a list of tokens
// TODO: Generate a pile of operations from these tokens

TreeOperations *newPile() {
  TreeOperations *po = (TreeOperations *)malloc(sizeof(TreeOperations *));
  return po;
}

Operation *newOperation() {
  Operation *op = (Operation *)malloc(sizeof(Operation *));
  return op;
}
