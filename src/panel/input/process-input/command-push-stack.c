#include <stdio.h>
#include <string.h>

#include "../../../../include/stack.h"

int commandPushStack(char *command, stack* _stack){

    push(_stack, command);


    return 0;
}