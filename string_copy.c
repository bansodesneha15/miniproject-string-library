#include<stdio.h>
#include<stdlib.h>
#include "string_lib.h"
void string_copy(char *, char *);


void string_copy(char *first, char *second){

while(*second){
	*first = *second;
	first++;
	second++;
}
	*first = '\0';
	
}
