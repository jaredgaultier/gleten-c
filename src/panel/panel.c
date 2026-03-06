#include <stdio.h>
#include <stdbool.h> // true and false use


#define DEBUG false


#include <string.h>
#include <stdlib.h> // pointers


#include "../include/panel.h"
#include "../include/gleten-string.h"
#include "../include/command-list.h"




bool inCommandList(char const *command){
    bool temp = false;

    for (size_t i = 0;*(commandList + i) != NULL;i++){
        if(DEBUG)printf("commandList[i]: %s\n", commandList[i]);
        if (strcmp(command, commandList[i]) == 0){
            return (temp = true);

        }
    }

    return temp;
}

int displayPanel(char const *projectTitle){
    size_t editingLine = 1;

    system("clear"); // Clear the terminal before displaying the panel

    printf("\t::Editing %s::\n", projectTitle);
    printf("\t   Editing line %zu\n", editingLine);

        // The two variables here are y and x, which are the coordinates of the cursor in the terminal, and they are used to print the project title in the center of the terminal.
        for (size_t i = 1;i < 10; i++)
            printf("%zu: \n", (size_t)i);


    char opc[100];

    // tf
    printf("\n\n\n>> ");

    while(strcmp(opc, "exit") != 0){
        _gotoxy(4, 15);printf("%s", cosmetic_longSpace);_gotoxy(4, 15);

        // clearCmd();


        fgets(opc, sizeof(opc), stdin);
        removeNewLine(opc, sizeof(opc));

        if (inCommandList(opc) == false)
            likenessFind(opc);

    }

    return 0;
}