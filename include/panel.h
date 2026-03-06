#ifndef PANEL_H
#define PANEL_H

int displayPanel(char const *projectTitle);

static char const *commandList[] = {
    "makefile",
    "deletefile",

    "fileExists",

    "makedir",
    "deletedir",
    "dirExists",

    "editWallpaper",
    "if",
    NULL
};

void cosmeticXAxisCleaning(size_t y, size_t y_limit);

static char cosmetic_line[] = "------------";
static char cosmetic_longSpace[] = "                      ";

#endif