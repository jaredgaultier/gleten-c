/*

This only applies for functional-commands
using non-functional commands will result
on weird issues.

*/


#include <stdio.h>
#include <string.h>

#include "../../../../include/command-id-def.h"

size_t defineId(char *command){

    if ( strcmp(command, "makefile") == 0 )
        return COMMAND_FILE_MANAGER_MAKEFILE;


    if ( strcmp(command, "removefile") == 0 )
        return COMMAND_FILE_MANAGER_REMOVEFILE;


    if ( strcmp(command, "makedirectory") == 0 )
        return COMMAND_DIRECTORY_MANAGER_MAKEDIRECTORY;


    if ( strcmp(command, "removedirectory") == 0 )
        return COMMAND_DIRECTORY_MANAGER_REMOVEDIRECTORY;

    


    return 0;
}