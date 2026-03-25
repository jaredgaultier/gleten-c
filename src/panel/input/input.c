#include <stdio.h>

#include "../../../include/command-list.h"
#include "../../../include/gleten-string.h"
#include "../../../include/stack.h"

/*

    SCHEMA

    First, checks if the command is
    a functional-command or a non-functional command
    if it's a functional one, calls command-stack.c
    if it's a non-functional one, calls their
    correspondent file (could be help.c or env-config.c)

    if it's neither case, then runs likeness-find.c
    to see if the user entered a command the wrong way,
    if likeness-find doesn't return anything just
    shows a message that the command wasn't found or
    simply doesn't exists.

    case 5 is for functional command which requires
    parameter or arguments, for more information
    look include/command-list.h

*/

int runInput(char *opc, stack* _stack){
    switch (commandType(opc))
    {
    case 1:
        break;
    
    case 2:
        //wip: call help.c
        break;

    case 3:
        if (inCommandList(opc, parameterCommandList)){
            return 5;
        }
        push(_stack, opc);
        // wip: call env-config.c
        break;

    default:

        likenessFind(opc);
        
        return 1;

        break;
    }

    return 0;
}