#ifndef PARSER_H_
#define PARSER_H_

enum Operator { ADD = '+', SUB = '-', MUL = '*', DIV = '/' };
enum Separator { EXP_BEGIN = '(', EXP_END = ')', WHITESPACE = ' ' };

typedef enum Operator Operator;
typedef enum Separator Separator;

typedef struct _Parser {
  char *buffer;
} Parser;

#endif // PARSER_H_
