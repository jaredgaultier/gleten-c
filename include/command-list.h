#ifndef COMMAND_LIST_H
#define COMMAND_LIST_H

#include <stddef.h>
#include <stdbool.h>

// belongs to panel.c
bool inCommandList(char const *command, char const *list[]);
int commandType(char *__opc);

static char const *functionalCommandList[] = {
    "help",
    "about",

    "makefile",
    "removefile",

    "fileExists",

    "makedirectory",
    "deletedirectory",
    "dirExists",

    "editWallpaper",
    "if",
    NULL
};


/*  Non-functional commands 

It could be help commands
or enviromental commands (Gleten configuration)

*/

static char const *helpCommandList[] = {
    "help",
    "about",
    NULL
};

static char const *enviromentalCommandList[] = {
    NULL
};

// -

static char const *parameterCommandList[] = {
    "makefile", 
    "removefile",

    "makedirectory",
    "removedirectory",

    "editWallpaper"
};

#endif
