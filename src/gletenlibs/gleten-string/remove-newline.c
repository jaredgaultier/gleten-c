#include <stdio.h>

void removeNewLine(char *str, size_t size){
    for (size_t i = 0; i < size;i++)
    {
        if (*(str + i) == '\n'){
            *(str + i) = '\0';
            break;
        }
    }
}