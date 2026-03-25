#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "../../../../include/command-list.h"

int commandType(char *__opc){
    if (inCommandList(__opc, helpCommandList)){
        
        return 1;
    
    }

    else if (inCommandList(__opc, enviromentalCommandList)){

        return 2;

    }

    else if (inCommandList(__opc, functionalCommandList)){
        
        return 3;
        
    }

    return -1;

}