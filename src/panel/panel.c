#include <stdio.h>
#include <stdbool.h> // true and false use


#define DEBUG false


#include <string.h>
#include <stdlib.h> // pointers


#include "../include/panel.h"
#include "../include/gleten-string.h"
#include "../include/command-list.h"


/*
The commands will be here, in this buffer
*/
static char **commandBuffer = NULL;

void userHelp(char *opt){
    if (strcmp(opt, "help")){
        printf("wip");
    }
}

int displayPanel(char const *projectTitle){
    // used for memory allocation
    int n = 0;
    
    size_t editingLine = 1;

    char _opc[100];

    system("clear"); // Clear the terminal before displaying the panel

    printf("\t::Editing %s::\n", projectTitle);
    printf("\tEditing line %zu\n", editingLine);

        // The two variables here are y and x, which are the coordinates of the cursor in the terminal, and they are used to print the project title in the center of the terminal.
        for (size_t i = 1;i < 10; i++)
            printf("%zu: \n", (size_t)i);



    // avoids stdin trash
    getchar();




    printf("\n>> ");

    while(strcmp(_opc, "exit") != 0){
        _gotoxy(4, 13);printf("%s", cosmetic_longSpace);_gotoxy(4, 13);

        // clearCmd();
        fgets(_opc, sizeof(_opc), stdin);
        removeNewLine(_opc, sizeof(_opc));

        /* 
        SCHEMA

        
        If the user input (_opt) is not in the command list,
        the program tries to compare it with the other commands
        in the list. If the stringLikeness function returns 1,
        likenessFind will show the user the closest command.

        If the user input is in the command list, the program
        checks whether the command is meant to display help
        information. The userHelp function compares _opc
        (as a parameter) with various keywords and shows
        the corresponding information.

        Otherwise, the program checks whether the command
        requires a parameter. If so, it asks the user for it.

        Finally, if everything is correct, the command
        (and its parameter, if any) is added to the
        commandBuffer.
        
        */

        if (inCommandList(_opc, commandList) == false){
            
            likenessFind(_opc);

        } else {
            if (inCommandList(_opc, ignoreCommandList)){
                
                userHelp(_opc);

            } else {

                if (inCommandList(_opc, parameterCommandList)){

                    printf("Parameter: ");
                    _gotoxy(0, 15);

                    // dynamic argBuffer[100];
                    char *argBuffer = malloc(100);

                    argBuffer[0] = '\"';


                    printf("1: %s", _opc);

                    char _cArg;
                    int i;


                    i = 1;
                    while ((_cArg = getchar()) != '\n'){
                        if (i >= 98 ){

                            char *temp = realloc(argBuffer, i + 1);

                            argBuffer = temp;

                        }
                        
                        argBuffer[i] = _cArg;
                        i++;
                    }
                    
                    /*
                    Let space to '\0' and '\"' in case
                    
                    the argument needed it
                    
                    argBuffer[limit + 1] = '\"'
                    
                    argBuffer[limit + 2] = '\0'
                    */
                    char *temp = realloc(argBuffer, i + 3);

                    argBuffer = temp;


                    printf("JOE BIDEN:%d", i);
                    getchar();
                    argBuffer[i + 1] = '\"';
                    argBuffer[i + 2] = '\0';

                    // Final result must be like this
                    // function"parameter"\0


                    strcat(_opc, argBuffer);


                    free(argBuffer);
            }
                
                char **temp = realloc(commandBuffer, (n + 1) * sizeof(char*));
                
                if (temp == NULL){
                    printf("Memory error!");
                    break;
                }

                commandBuffer = temp;

                commandBuffer[n] = malloc(strlen(_opc) + 1);
                strcpy(commandBuffer[n], _opc);
                

                cosmeticXAxisCleaning(16, 25);
                _gotoxy(3, n + 3);
                printf(" %s", commandBuffer[n]);
                
                n++;
            }

        }
        
        memset(_opc, 0, sizeof(_opc));

    }

    for (size_t i = 0;i < (size_t)n;i++){
        free(commandBuffer[i]);
    }

    free(commandBuffer);

    return 0;
}