#include <stdio.h>
#include <stdlib.h>

void clearCmd() {

	#ifdef __WIN32__
		system("cls");

	#elif __APPLE__
		system("clear");

	#elif __linux__
		system("clear");

	#endif
}