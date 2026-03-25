#include <stdio.h>
#include <string.h>

#include "../../../../include/panel.h"
#include "../../../../include/gleten-string.h"

void parameterControl(char *opc, char *paramBuffer, size_t bufferSize){
    if (
        strcmp(opc, "makefile") == 0 ||
        strcmp(opc, "removefile") == 0 ||
        strcmp(opc, "makedirectory") == 0 ||
        strcmp(opc, "removedirectory") == 0
    ){
        printf("File/directory name: ");
        fgets(paramBuffer, bufferSize, stdin);
        removeNewLine(paramBuffer, bufferSize);
    }
}