#include<stdio.h>
#include<stdlib.h>
#include "string_lib.h"

int string_length(char *);

int string_length(char *l){
	int c = 0;
	
	while(*(l+c))
		c++;
		
	return c;
}


