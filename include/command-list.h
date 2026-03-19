#ifndef COMMAND_LIST_H
#define COMMAND_LIST_H

#include <stddef.h>

// belongs to panel.c
bool inCommandList(char const *command, char const *list[]);


static char const *commandList[] = {
    "help",
    "about",

    "makefile",
    "removefile",

    "fileExists",

    "makedir",
    "deletedir",
    "dirExists",

    "editWallpaper",
    "if",
    NULL
};


// - Non-functional commands 

static char const *ignoreCommandList[] = {
    "help",
    "about",
    NULL
};

// -

static char const *parameterCommandList[] = {
    "makefile", 
    "deletefile",

    "makedir",
    "deletedir",

    "editWallpaper"
};

#endif
