#ifndef PANEL_H
#define PANEL_H

#include <stdio.h>

int displayPanel(char const *projectTitle);

void cosmeticXAxisCleaning(size_t y, size_t y_limit);

static char cosmetic_line[] = "------------";
static char cosmetic_longSpace[] = "                      ";

#endif