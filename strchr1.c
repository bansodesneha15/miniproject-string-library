#include<stdio.h>
#include<stdlib.h>
char *strchr1(const char *, int );
int main(){

char *a, *s;
char ch;
int n;
scanf("%d", &n);

a = (char*)malloc(n*sizeof(char));

scanf("%s %c", a, &ch);

s = strchr1(a, ch);

/*	if (s != NULL)
		printf ("found at %s\n", s);
	return 0; */
}

char *strchr1(const char *s, int c){
	
	const char ch = c;
	int i=0;
		for ( ; *s != ch; s++){
			i++;
		}
        
		if (*s == '\0')
			return 0;
		printf("found at %d\n", i);
	
		return (char *)s;
}


