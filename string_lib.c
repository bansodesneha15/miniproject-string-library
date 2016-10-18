#include<stdio.h>
#include<stdlib.h>
#include "string_lib.h"

char *stpcpy1(char * to, const char * from){

	for (; (*to = *from); ++from, ++to);
	return(to);
}

void string_catenate(char *s1, char *s2){
int i;
int j;
 i = string_length(s1);
 
for (j = 0; s2[j] != '\0'; i++, j++) {
      s1[i] = s2[j];
}
 
   s1[i] = '\0';
}

void string_copy(char *first, char *second){

while(*second){
	*first = *second;
	first++;
	second++;
}
	*first = '\0';
	
}

char* string_dup(char *s1){

	int l = string_length(s1);
	char s2[l];

	string_copy(s2, s1);

	return ;
}

int string_length(char *l){
	int c = 0;
	
	while(*(l+c))
		c++;
		
	return c;
}

char *strchr1(const char *s, int c){
	
	const char ch = c;
	int i=0;
	for ( ; *s != ch; s++){
		i++;
	}
        
	if (*s == '\0')
		return 0;
	printf("%d", i);
	
	return (char *)s;
}

char *strncpy1(char *dst, const char *src, size_t len){

	char *s = dst;
	int n = len;
		while( n > 0 && *src != '\0'){
			*s++ = *src++;
			--n;
		}
		while(n > 0){
		*s++ = '\0';
		--n;
		}
		return dst;
}

size_t strcspn1(const char *s1, register const char *s2){
	                     
	register const char *p, *spanp;
	register char c, sc;

	/*
	 * Stop as soon as we find any character from s2.  Note that there
	 * must be a NUL in s2; it suffices to stop when we find that, too.
	 */
	for (p = s1;;) {
		c = *p++;
		spanp = s2;
		do {
			if ((sc = *spanp++) == c)
				return (p - 1 - s1);
		} while (sc != 0);
	}
}

int strcmp1(const char *s1, const char *s2){
	for ( ; *s1 == *s2; s1++, s2++)
		if (*s1 == '\0')
	  		return 0;
    	
	return ((*(unsigned char *)s1 < *(unsigned char *)s2) ? -1 : +1);
}

char *stpncpy1(char *dst, const char *src, size_t len){

size_t n = strlen (src);
	if (n > len)
	n = len;
	return strncpy (dst, src, len);
}

char *strncat1(char *dst, const char *src, register size_t n){
	if (n != 0) {
		register char *d = dst;
		register const char *s = src;

		while (*d != 0)
			d++;
		do {
			if ((*d = *s++) == 0)
				break;
			d++;
		} while (--n != 0);
		*d = 0;
	}
	return (dst);
}

char *strstr1(const char *in, const char *str){
    char c;
    size_t len;

    c = *str++;
    if (!c)
        return (char *) in;	// Trivial empty string case

    len = strlen(str);
    do {
        char sc;

        do {
            sc = *in++;
            if (!sc)
                return (char *) 0;
        } while (sc != c);
    } while (strncmp(in, str, len) != 0);

    return (char *) (in - 1);
}

int strncasecmp1(const char *s1, const char *s2, size_t n){
	unsigned char c1, c2;
	int len;
          if (!len)
                  return 0;
  
          do {
                  c1 = *s1++;
                  c2 = *s2++;
                  if (!c1 || !c2)
                          break;
                  if (c1 == c2)
                          continue;
                  c1 = tolower(c1);
                  c2 = tolower(c2);
                  if (c1 != c2)
                          break;
          } while (--len);
          return (int)c1 - (int)c2;

}

int strcasecmp1(const char *s1, const char *s2){

	const unsigned char *p1 = (const unsigned char *) s1;
	const unsigned char *p2 = (const unsigned char *) s2;
	int result;

		if (p1 == p2)
		    return 0;

		while ((result = TOLOWER (*p1) - TOLOWER (*p2++)) == 0)
    		if (*p1++ == '\0')
      			break;

  		return result;


}




