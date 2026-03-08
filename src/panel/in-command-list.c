#include <stdio.h>
#include <stdbool.h>

#include "../../include/debug.h"

bool inCommandList(char const *command, char const *list[]){
    bool temp = false;

    for (size_t i = 0;*(list + i) != NULL;i++){
        if(DEBUG)printf("list[i]: %s\n", list[i]);

        if (strcmp(command, list[i]) == 0){
            return (temp = true);

        }
    }

    return temp;
}