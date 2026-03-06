#include <stdio.h>

#include "../include/panel.h"
#include "../include/gleten-string.h"


void cosmeticXAxisCleaning(size_t y, size_t y_limit){
	for (size_t i = y;i < y_limit;i++){

        _gotoxy(0, i);
        printf("%s", cosmetic_longSpace);

    }
}