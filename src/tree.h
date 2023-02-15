#ifndef TREE_H_
#define TREE_H_

#include <stdlib.h>
typedef struct _Operation Operation;
typedef struct _TreeOperations TreeOperations;

struct _Operation {
  char operation;
  double arg1, arg2;
};

struct _TreeOperations {
  Operation *op;
  TreeOperations *leftNode;
  TreeOperations *rightNode;
};

inline TreeOperations *newTree() {
  TreeOperations *to = (TreeOperations *)malloc(sizeof(TreeOperations *));
  return to;
}

inline Operation *newOperation() {
  Operation *op = (Operation *)malloc(sizeof(Operation *));
  return op;
}

#endif // TREE_H_
