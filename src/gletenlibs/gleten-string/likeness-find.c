#include <stdio.h>
#include <stdlib.h>

#include "../../../include/command-list.h"
#include "../../../include/debug.h"
#include "../../../include/gleten-string.h"
#include "../../../include/panel.h"

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
            for (size_t i = 0;i < (size_t)n;i++)
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

    for (size_t i = 0;i < (size_t)n;i++){
        free(arLikeness[i]);
    }

    free(arLikeness);

}