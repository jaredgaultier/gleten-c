#include <stdio.h>
#include <stdlib.h>


#include "../include/panel.h"
#include "../include/debug.h"
#include "../include/gleten-string.h"

int readTemp(){
    FILE *fptr;
    char fileBuffer[80];
    char projectName[31];


    fptr = fopen("temp.txt", "r");
    
    if (fptr == NULL)
        return 1;

    char c;
    size_t n = 0;
    
    while ((c = fgetc(fptr)) != EOF){
        fileBuffer[n] = c;

        if(DEBUG)printf("dbg;c: %c\n", fileBuffer[n]);
        
        n++;
    }

    // WIP: NOT WORKING, BE CAREFUL
    // Memory violation issues, don't run
    fileBuffer[n + 1] = '\0';

    if (fileBuffer[0] == '0'){
        for(size_t i = 2;fileBuffer[i] != '<' || fileBuffer[i] != '\0';i++){
            projectName[i-2] = fileBuffer[i];
        }
    }

    if(DEBUG)printf("dbg;projectName: %s", projectName);


    fclose(fptr);

    // displayPanel((char*)projectName);

    return 0;
}

int main(void){
    char opc;
    
    printf("1: Make a new project\n");
    printf("2: Edit an existing project\n");
    printf("3: Delete a project\n>>");
    opc = getchar();


    switch (opc) {
        case '1':

            system("python3 src/gletenlibs/info-control/json-makeproject.py");
            break;

        case '2':

            system("python3 src/gletenlibs/info-control/json-editproject.py");            
            if(readTemp() != 0)
                printf("Error al leer temp.txt");
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
