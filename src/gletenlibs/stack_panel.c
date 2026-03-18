#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../include/stack.h"



void stackConstructor(stack *__a){

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

void pop(stack *st, char *value){
    for (size_t i = 0;i < (size_t)st -> countElements;i++){
        
        if (strcmp(st->elements[i], value) == 0){
            
            free(st->elements[i]);
            
            for (size_t j = i;j < (size_t)st -> countElements-1;j++)
                st->elements[j] = st -> elements[j + 1];

            st->countElements -= 1;
            break;   
        }

    }
    
    
}

void cleanStackMemory(stack *st){

    for (size_t i = 0;i < (size_t)st -> countElements;i++){
        free(st->elements[i]);
    }

    free(st->elements);
}
