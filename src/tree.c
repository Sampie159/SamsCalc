#include "tree.h"
#include <stdlib.h>

TreeOperations *newTree() {
  TreeOperations *to = (TreeOperations *)malloc(sizeof(TreeOperations *));
  return to;
}

Operation *newOperation() {
  Operation *op = (Operation *)malloc(sizeof(Operation *));
  return op;
}
