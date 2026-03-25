#ifndef PANEL_H
#define PANEL_H

#include <stdio.h>
#include <stdbool.h>

#include "stack.h"

int displayPanel(char const *projectTitle);

int runInput(char *opc, stack* _stack);

void parameterControl(char *opc, char* paramBuffer, size_t sizeBuffer);







// for visual functions

void cosmeticXAxisCleaning(size_t y, size_t y_limit);

static char cosmetic_line[] = "------------";
static char cosmetic_longSpace[] = "                               ";




#endif
