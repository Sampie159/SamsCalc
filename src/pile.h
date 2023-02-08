#ifndef PILE_H_
#define PILE_H_

typedef struct _Operation Operation;
typedef struct _PileOperations PileOperations;

struct _Operation {
  char operation;
  double arg1, arg2;
};

struct _PileOperations {
  Operation *op;
  PileOperations *next;
};

double solveOperation(Operation *);

double solvePileOperations(PileOperations *);

#endif // PILE_H_
