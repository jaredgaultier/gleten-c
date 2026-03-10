#ifndef PANEL_H
#define PANEL_H

#include <stdio.h>
#include <stdbool.h>

int displayPanel(char const *projectTitle);

void cosmeticXAxisCleaning(size_t y, size_t y_limit);

static char cosmetic_line[] = "------------";
static char cosmetic_longSpace[] = "                               ";

// veriy input dir

bool inCommandList(char const *command, char const *list[]);

#endif