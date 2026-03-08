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
//static char **commandBuffer = NULL;




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

int displayPanel(char const *projectTitle){
    size_t editingLine = 1;

    char _opc[100];

    system("clear"); // Clear the terminal before displaying the panel

    printf("\t::Editing %s::\n", projectTitle);
    printf("\t   Editing line %zu\n", editingLine);

        // The two variables here are y and x, which are the coordinates of the cursor in the terminal, and they are used to print the project title in the center of the terminal.
        for (size_t i = 1;i < 10; i++)
            printf("%zu: \n", (size_t)i);


    // tf
    getchar();
    printf("\n\n\n>> ");

    while(strcmp(_opc, "exit") != 0){
        _gotoxy(4, 15);printf("%s", cosmetic_longSpace);_gotoxy(4, 15);

        // clearCmd();
        fgets(_opc, sizeof(_opc), stdin);
        removeNewLine(_opc, sizeof(_opc));

        if (inCommandList(_opc, commandList) == false){
            
            likenessFind(_opc);

        } else {
            // if (inCommandList(_opc, ignoreCommandList))

            _gotoxy(3, 3);

            cosmeticXAxisCleaning(18, 25);
        }

    }

    return 0;
}