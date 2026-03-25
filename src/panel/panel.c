#include <stdio.h>
#include <stdbool.h> // true and false use


#define DEBUG false


#include <string.h>
#include <stdlib.h> // pointers


#include "../include/panel.h"
#include "../include/gleten-string.h"
#include "../include/command-list.h"
#include "../include/stack.h"

// Here will be all the command input by the user
stack commandStack;

void userHelp(char *opt){
    if (strcmp(opt, "help")){
        printf("wip");
    }
}

int displayPanel(char const *projectTitle){

    size_t visualXPos = 3;
    

    system("clear"); // Clears the terminal before displaying the panel

    printf("\t::Editing %s::\n", projectTitle);
    printf("\tEditing line %zu\n", (visualXPos - 1));
    for (size_t i = 1;i < 10; i++)
        printf("%zu: \n", (size_t)i);



    // avoids stdin trash
    getchar();

    char _opc[100] = {0};


    char _opcParameter[254] = {0};

    // INITS STACK
	stackInit(&commandStack);
    stack *_commandStack = &commandStack; // pointer to command stack

    size_t pushCount = 0;

    while(strcmp(_opc, "exit") != 0){
        // reset _opc and _opcParameter buffer
        memset(_opc, 0, sizeof(_opc));
        memset(_opcParameter, 0, sizeof(_opcParameter));
        
        
        cosmeticXAxisCleaning(12, 30);

        _gotoxy(4, 12);
        printf("%s", cosmetic_longSpace);

        _gotoxy(4, 12);

        printf("\n>> ");


        fgets(_opc, sizeof(_opc), stdin); // Reads user input
        removeNewLine(_opc, sizeof(_opc)); // Removes \n at the end of _opc

        int runInputResult = runInput(_opc, &commandStack);

        if (runInputResult == 5){

            parameterControl(_opc, _opcParameter, sizeof(_opcParameter));
            
            char _temp[254] = {0};
            char _pushValue[354] = {0};
            
            for (size_t i = 0;_opcParameter[i] != '\0';i++){

                _temp[i] = _opcParameter[i];

                printf("%c", _temp[i]);

            }

            snprintf(_pushValue, sizeof(_pushValue), "%s\"%s\"", _opc, _temp);

            push(&commandStack, _pushValue);

            _gotoxy(4, visualXPos);
            
            if ((size_t)_commandStack -> countElements > pushCount){
                
                printf("%s", _commandStack -> elements[pushCount]);

                pushCount++;

                visualXPos++;
            }
        }

        if(runInputResult == 1){
            
            _gotoxy(4, visualXPos);
            
            if ((size_t)_commandStack -> countElements > pushCount){
                
                printf("%s", _commandStack -> elements[pushCount]);

                
                pushCount++;

                visualXPos++;
            }
        }

    }

    // LIBERATES STACK HEAP DATA
    cleanStackMemory(&commandStack);

    return 0;
}