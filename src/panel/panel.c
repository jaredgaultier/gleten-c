#include <stdio.h>
#include <stdbool.h> // true and false use


#define DEBUG false


#include <string.h>
#include <stdlib.h> // pointers

#include "panel.h"
#include "../gletenlibs/gleten-string/gleten-string.h"


/*
#include "gletenlibs/panel/panel.h"
#include "gletenlibs/gleten-string/gleten-string.h"
#include "gletenlibs/command-list.h"
*/


void likenessFind(char *command){
    char **arLikeness = NULL;
    int n = 0;

    for (size_t i = 0;*(commandList + i) != NULL;i++){
        if(DEBUG)
            printf("comparing: %s-%s >> %d\n", (char*)commandList[i], command, stringLikeness((char*)commandList[i], command) );

        if(stringLikeness((char*)commandList[i], command) == 1){
            char **temp = realloc(arLikeness, (n + 1) * sizeof(char*));

            if (temp == NULL){
                printf("Memory error!");
                break;
            }

            arLikeness = temp;
            arLikeness[n] = malloc(strlen(commandList[i]) + 1);
            strcpy(arLikeness[n], commandList[i]);
            n++;
        }

    }


    if(n > 0){
        cosmeticXAxisCleaning(18, 30);
        _gotoxy(1, 18);
        printf("%s\n", cosmetic_line);

        printf("Did you mean \'%s\'?\n", *arLikeness);

        if (n > 1){
            for (size_t i = 0;i < n;i++)
            {
                _gotoxy(1,20 + i);
                printf("or \'%s\'?\n", arLikeness[i]);
            }
        }

    }
// y:31
                

    else if(n == 0){
        printf("Unknown command.");
    }

    for (size_t i = 0;i < n;i++){
        free(arLikeness[i]);
    }

    free(arLikeness);

}

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



        // inCommandList(opc) ? commandBuffer[i] == opc : 

    }

    return 0;
}


int main(){
    displayPanel("poponga");

    return 0;
}

// clang ../gletenlibs/gleten-string/_gotoxy.c ../gletenlibs/gleten-string/likeness.c ../gletenlibs/gleten-string/remove-newline.c ../gletenlibs/gleten-string/clear.c panel.c -o panel
