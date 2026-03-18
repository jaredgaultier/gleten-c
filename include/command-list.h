#ifndef COMMAND_LIST_H
#define COMMAND_LIST_H

#include <stddef.h>

static char const *commandList[] = {
    "help",
    "about",

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
