// old function asf but idc
#include <stdio.h>

void _gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}