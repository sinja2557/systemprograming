#include <string.h>

void mystrcpy(char *dst, char *src){

	while(*src != '\0'){
		*dst++ = *src++;
	}	

}

