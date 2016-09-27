#include<stdio.h>
#include<stdlib.h>
#include "string_lib.h"

void string_catenate(char *, char *);


void string_catenate(char *s1, char *s2){
int i;
int j;
 i = string_length(s1);
 
for (j = 0; s2[j] != '\0'; i++, j++) {
      s1[i] = s2[j];
}
 
   s1[i] = '\0';
}




















