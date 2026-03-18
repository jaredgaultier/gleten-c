#ifndef PANEL_H
#define PANEL_H

#include <stdio.h>
#include <stdbool.h>

int displayPanel(char const *projectTitle);







// for visual functions

void cosmeticXAxisCleaning(size_t y, size_t y_limit);

static char cosmetic_line[] = "------------";
static char cosmetic_longSpace[] = "       ";










// belongs to panel.c

bool inCommandList(char const *command, char const *list[]);

#endif
