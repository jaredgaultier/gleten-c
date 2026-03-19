#ifndef STACK_H
#define STACK_H


typedef struct _stack {

    char **elements;
    int countElements;
    int elementId;


} stack;


void stackInit(stack *__a);
void push(stack *st, char *value);
void pop(stack *st, char *value);
void cleanStackMemory(stack *st);


#endif