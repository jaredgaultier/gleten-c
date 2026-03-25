#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../include/stack.h"
#include "../../include/debug.h"



void stackInit(stack *__a){

    __a->elements = NULL;
    __a->countElements = 0;
}

void push(stack *st, char *value){

    char **temp = realloc(st->elements, (st->countElements + 1) * sizeof(*st->elements));    

    if (temp == NULL){
        printf("Memory error!");
        return;
    }


    st -> elements = temp;
    st -> elements[st -> countElements] = malloc(strlen(value) + 1);
    strcpy(st -> elements[st -> countElements], value);

    st->countElements++;
}

void pop(stack *st){
    if (st->countElements == 0)
        return;

    free(st->elements[st->countElements - 1]);
    st->countElements--;

    char **temp = realloc(
        st->elements,
        st->countElements * sizeof(*st->elements)
    );

    if (temp != NULL || st->countElements == 0)
        st->elements = temp;
    
}

void cleanStackMemory(stack *st){

    for (size_t i = 0;i < (size_t)st -> countElements;i++){
        free(st->elements[i]);
    }

    free(st->elements);
}
