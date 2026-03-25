#ifndef STACK_H
#define STACK_H


typedef struct _stack {

    char **elements;
    int countElements;


} stack;


void stackInit(stack *__a);
void push(stack *st, char *value);
void pop(stack *st);
void cleanStackMemory(stack *st);


#endif