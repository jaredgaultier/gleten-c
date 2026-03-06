#include <stdio.h>
#include <stdlib.h>


#include "../include/panel.h"



int main(void){

    printf("Gleten C version (1.0)\n");

    char opc;
    
    printf("1: Make a new project\n");
    printf("2: Edit an existing project");
    printf("3: Delete a project\n>>");
    opc = getchar();


    switch (opc) {
        case '1':

            system("python3 src/gletenlibs/info-control/json-makeproject.py");
            break;

        case '2':

            system("python3 src/gletenlibs/info-control/json-editproject.py");            
            break;

        case '3':

            system("python3 src/gletenlibs/ihfo-control/json-deleteproject.py");
            break;

        default:
            printf("Invalid option.\n");
            break;
    }

    




    return 0;
}