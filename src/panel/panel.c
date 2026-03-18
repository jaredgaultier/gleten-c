#include <stdio.h>
#include <stdbool.h> // true and false use


#define DEBUG false


#include <string.h>
#include <stdlib.h> // pointers


#include "../include/panel.h"
#include "../include/gleten-string.h"
#include "../include/command-list.h"
#include "../include/stack.h"

/*
typedef struct command {
    
    char **commandBuffer;
    size_t commandCount;
    size_t commandId;

} c;*/



// Here will be all the command input by the user
stack commandStack;


void userHelp(char *opt){
    if (strcmp(opt, "help")){
        printf("wip");
    }
}

int displayPanel(char const *projectTitle){
    
    size_t editingLine = 1;

    char _opc[100];

    system("clear"); // Clear the terminal before displaying the panel

    printf("\t::Editing %s::\n", projectTitle);
    printf("\tEditing line %zu\n", editingLine);
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

		// INITS STACK
		stackConstructor(&commandStack);

	
		// LIBERATES STACK HEAP DATA
		cleanStackMemory(&commandStack);
	}

    return 0;
}
