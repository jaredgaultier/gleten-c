#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _stack {

    char **elements;
    int count_elements;


} stack;

void stackConstructor(stack *__a){

    __a->elements = NULL;
    __a->count_elements = 0;
}

void push(stack *st, char *value){
    int n = 0;

    char **temp = realloc(st->elements, (st->count_elements + 1) * sizeof(*st->elements));    

    if (temp == NULL){
        printf("Memory error!");
        return;
    }


    st->elements = temp;
    st->elements[st->count_elements] = malloc(strlen(value) + 1);
    strcpy(st->elements[st->count_elements], value);

    st->count_elements++;
}

void pop(stack *st, char *value){
    for (size_t i = 0;i < st->count_elements;i++){
        
        if (strcmp(st->elements[i], value) == 0){
            
            free(st->elements[i]);
            
            for (size_t j = i;j < st->count_elements-1;j++)
                st->elements[j] = st->elements[j + 1];

            st->count_elements -= 1;
            break;   
        }

    }
    
    
}

void cleanStackMemory(stack *st){

    for (size_t i = 0;i < st->count_elements;i++){
        free(st->elements[i]);
    }

    free(st->elements);
}