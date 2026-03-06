#include <stdio.h>
#include <string.h>


#include "../include/gleten-string.h"



int stringLikeness(char *str1, char *str2){

	float likeness_percentage;
	int likeness_count = 0;

	int str1_size = strlen(str1);
	int str2_size = strlen(str2);


	size_t min_size = (str1_size < str2_size) ? str1_size : str2_size;

	for(size_t i = 0;i < min_size;i++){

		if(str1[i] == str2[i])
			likeness_count += 1;

	}

	likeness_percentage = ((float)likeness_count/(float)str1_size)*100;

	// below 50% return 0; above 50% return 1;
	return (likeness_percentage > 60) ? 1 : 0;

}