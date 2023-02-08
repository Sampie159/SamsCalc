#ifndef TREE_H_
#define TREE_H_

typedef struct _Operation Operation;
typedef struct _ListOperations ListOperations;

struct _Operation {
  char operation;
  double arg1, arg2;
};

struct _ListOperations {
  Operation *op;
  ListOperations *next;
};

double solveOperation(Operation *);

double solveListOperations(ListOperations *);

#endif // TREE_H_
