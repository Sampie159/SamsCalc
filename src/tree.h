#ifndef TREE_H_
#define TREE_H_

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

TreeOperations *newPile();

Operation *newOperation();

double solveOperation(Operation *);

double solveTreeOperations(TreeOperations *);

#endif // TREE_H_
