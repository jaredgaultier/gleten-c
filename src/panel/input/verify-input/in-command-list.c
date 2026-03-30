#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../../../../include/debug.h"
#include "../../../../include/panel.h"

bool inCommandList(char const *command, char const *list[]){
    bool btemp = false;

    for (size_t i = 0;list[i] != NULL;i++){        

        if (strcmp(command, list[i]) == 0){
            return (btemp = true);

        }
    }

    return btemp;
}