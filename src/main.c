#include <stdio.h>
#include <stdlib.h>


#include "panel/panel.h"



int main(int argc, char const *argv[]){

    printf("Gleten C version (1.0)\n");

    displayPanel("poponga");

    char opc;
    
    printf("1: Make a new project\n");
    printf("2: Edit an existing project\n>>");
    printf("3: Delete a project");
    opc = getchar();


    switch (opc) {
        case '1':

            system("python3 gletenlibs/info-control/json-makeproject.py");
            break;

        case '2':

            system("python3 gletenlibs/info-control/json-editproject.py");            
            break;

        case '3':

            system("python3 gletenlibs/ihfo-control/json-deleteproject.py");
            break;

        default:
            printf("Invalid option.\n");
            break;
    }

    




    return 0;
}