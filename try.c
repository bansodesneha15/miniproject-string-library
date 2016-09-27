#include<stdio.h>
#include<stdlib.h>
#include "string_lib.h"
#include "string_lib.c"
int main(){

char *a, *b;

int n, l;
scanf("%d", &n);

a = (char *)malloc(n*sizeof(char));
b = (char *)malloc(n*sizeof(char));
scanf("%s", a);
scanf("%s", b);

string_copy(a, b);
l = string_length(a);
printf("%d\n", l);
printf("%s", a);

return 0;
}
