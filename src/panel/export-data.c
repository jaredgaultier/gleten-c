#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "../../include/stack.h"


int exportData(stack *_stack, char *projectTitle){

    
    char *dataBuffer = NULL;
    
    char projectPath[100] = "gleten-projects/";

    snprintf(projectPath, sizeof(projectPath), "gleten-projects/%s/data/%s.glt", projectTitle, projectTitle);

    FILE *fptr = fopen(projectPath, "w");
    if (fptr == NULL){

        printf("there was an issue opening the file.");
        
        return 1;
    }


    for (size_t i = 0;i < (size_t)_stack -> countElements;i++){
        
        char *temp = realloc(dataBuffer, strlen(_stack -> elements[i]) + 2);
        if (temp == NULL){
            printf("Memory error!");
            return 2;
        }

        dataBuffer = temp;

        for (size_t j = 0;_stack -> elements[i][j] != '\0';j++){

            dataBuffer[j] = _stack -> elements[i][j];

            if (_stack -> elements[i][j + 1] == '\0'){

                dataBuffer[j + 1] = '\n';
                
                dataBuffer[j + 2] = '\0';
            }

        }


        fputs(dataBuffer, fptr);


    }

    free(dataBuffer);
    

    fclose(fptr);

    char runPy[200];
    snprintf(runPy, sizeof(runPy), "python3 src/gletenlibs/data-interpreter/read-data.py \"%s\"", projectTitle);

    system(runPy);

    return 0;
}