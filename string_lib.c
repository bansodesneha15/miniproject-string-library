/*****************************************************************************
 * Copyright (C) Sneha Sunil Bansodes bansodess15.it@coep.ac.in
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include "string_lib.h"
#include <sys/cdefs.h>
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <ctype.h>
#include <limits.h>
#include <string.h>
#define TOLOWER(Ch) (isupper (Ch) ? tolower (Ch) : (Ch))



char *stpcpy1(char * s1, const char * s2){

	for (; (*s1 = *s2); ++s2, ++s1);
	return(s1);
}


void strcat1(char *s1, const char *s2){
	int i;
	int j;
	i = strlen1(s1);
 
		for (j = 0; s2[j] != '\0'; i++, j++) {
	     	 s1[i] = s2[j];
		}
	 
		s1[i] = '\0';
}


char *strchr1(const char *s1, int c){
	
	const char ch = c;
	int i=0;
	
	for ( ; *s1 != ch; s1++){
		i++;
	}
        
	if (*s1 == '\0')
		return 0;
	//printf("found character at %d\n\n", i);
	
	return (char *)s1;
}


int strcmp1(const char *s1, const char *s2){
        int l1, l2, i = 0;
	l1 = strlen(s1);
	l2 = strlen(s2);
		if ( l2 > l1)
			return -1;
		else if ( l1 > l2) 
			return +1;
		else 
			do{
				if(s1[i] != s2[i])
					return ((*(char *)s1 < *(char *)s2) ? -1 : +1);
				else
					i++;
			}
			while( *s1 && *s2 );
			return 0;
}


int strcoll1(const char *s1, const char *s2){
	
	return (strcmp1(s1, s2));
}


void strcpy1(char *s1, const char *s2){

	while(*s2){
		*s1 = *s2;
		s1++;
		s2++;
	}
		*s1 = '\0';
}


size_t strcspn1(const char *s1, const char *s2){
	                     
	const char *p, *sp;
	char c, sc;

	for (p = s1;;) {
		c = *p++;
		sp = s2;
		do {
			if ((sc = *sp++) == c)
				return (p - 1 - s1);
		} while (sc != 0);
	}
}


char *strdup1(const char *s1){

	int l = strlen1(s1);
	char s2[l];

	strcpy1(s2, s1);
	return ;
}


char *strfry1(char *s1){
	int l, m, n, j = 0;
	l = strlen1 (s1);
	if ( s1 == NULL)
		return;
	srand(time(NULL));
	char c;
	l = strlen1(s1);
	while(j < l){
		m = rand() % l;
		n = rand() % l;
		c = s1[m];
		s1[m] = s1[n];
		s1[n] = c;
		j++;
	}	
	return s1;
}


size_t strlen1(const char *l){
	int c = 0;
	
	while(*(l+c))
		c++;
	return c;
}


char *strncat1(char *s1, const char *s2, size_t n){
	if (n != 0) {
		char *d = s1;
		const char *s = s2;

		while (*d != 0)
			d++;
		do {
			if ((*d = *s++) == 0)
				break;
			d++;
		} while (--n != 0);
		*d = 0;
	}
	return (s1);
}


int strncmp1(const char *s1, const char *s2, size_t n){
	
	int l1, l2, i = 0;
	l1 = strlen(s1);
	l2 = strlen(s2);
		if ( l2 > l1)
			return -1;
		else if ( l1 > l2) 
			return +1;
		else 
			do{
				if(s1[i] != s2[i])
					return ((*(char *)s1 < *(char *)s2) ? -1 : +1);
				else
					i++;
			}
			while( i < n);
			return 0;
}

		
char *strncpy1(char *s1, const char *s2, size_t len){

	char *s = s1;
	int n = len;
		while( n > 0 && *s2 != '\0'){
			*s++ = *s2++;
			--n;
		}
		while(n > 0){
		*s++ = '\0';
		--n;
		}
		return s1;
}


char *strpbrk1(const char *s1, const char *s2){
	
	const char *s;
	int c, d;

		while ((c = *s1++) != 0) {
			for (s = s2; (d = *s++) != 0;)
				if (d == c)
					return ((char *)(s1 - 1));
		}
	return (NULL);
}


char *strrchr1(const char *cp, int ch){
	char *s;
	char c;

		for (s = (char *) 0; c = *cp; cp++) {
			if (c == ch)
				s = (char *) cp;
		}
	return s;
}


char *strsep1(char **s1, const char *s2){
	char *s;
	const char *d;
	int c, sc;
	char *tok;

	if ((s = *s1) == NULL)
		return (NULL);
	for (tok = s;;) {
		c = *s++;
		d = s2;
		do {
			if ((sc = *d++) == c) {
				if (c == 0)
					s = NULL;
				else
					s[-1] = 0;
				*s1 = s;
				return (tok);
			}
		} while (sc != 0);
	}
}


size_t strspn1(const char *s1, const char *s2){

	const char *p = s1, *s;
	char c, sc;

	
cont:
	
	c = *p++;
	for (s = s2; (sc = *s++) != 0;)
		if (sc == c)
			goto cont;
	return (p - 1 - s1);
}


char *strstr1(const char *s1, const char *s2){
	char c;
	size_t len;

	c = *s2++;
		
		if (!c)
		        return (char *) s1;	

		len = strlen1(s2);
		do {
			char sc;

		do {
			sc = *s1++;
				if (!sc)
				        return (char *) 0;
		} while (sc != c);
		} while (strncmp(s1, s2, len) != 0);

		return (char *) (s1 - 1);
}


char *strtok1(char *s1, const char *s2){
	char *s;
	int c, sc;
	char *tok;
	static char *last;

		if (s1 == NULL && (s1 = last) == NULL)
			return 0;

	cont:
		c = *s1++;
		for (s = (char *)s2; (sc = *s++) != 0;) {
			if (c == sc)
				goto cont;
		}
		if (c == 0) {		
			last = NULL;
			return (NULL);
		}
		tok = s1 - 1;
		for (;;) {
			c = *s1++;
			s = (char *)s2;
			do {
				if ((sc = *s++) == c) {
					if (c == 0)
						s1 = NULL;
					else
						s1[-1] = 0;
					last = s1;
					return (tok);
				}
			} while (sc != 0);
		}
}


size_t strxfrm1(char *s1, const char *s2, size_t n){
	
	size_t s2len, sizetocopy;

	s2len = strlen1(s2);
		
		if (n != 0) {

			sizetocopy = s2len < n ? s2len : n;
			(void)memcpy1(s1, s2, sizetocopy);
			s1[sizetocopy] = 0;
	
		}
	return (n);
}


char *stpncpy1(char *s1, const char *s2, size_t len){

	size_t n = strlen1(s2);
		
		if (n > len)
			n = len;
	return strncpy1 (s1, s2, len);
}


void *memcpy1(void *s1, const void *s2, size_t len){

	char *s, *d;
	
	s = (char *)s2;
	d = (char *)s1;
	
		while (len-- > 0)
			*d++ = *s++;
		return d;
}


int strcasecmp1(const char *s1, const char *s2){
  	  
	int c1, c2;
		
		do {
                	c1 = tolower(*s1++);
                	c2 = tolower(*s2++);
          	} while (c1 == c2 && c1 != 0);
        return c1 - c2;
}


int strncasecmp1(const char *s1, const char *s2, size_t n){
	
	char c1, c2;
	int len = n;
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


char *index1(const char *s1, int c){
	
	const char ch = c;
	int i=0;
		for ( ; *s1 != ch; s1++){
			i++;
		}
        
		if (*s1 == '\0')
			return 0;
		
	
		return (char *)s1;
}


char *rindex1(const char *s1, int c){
	char *s;
	char ch;

	for (s = (char *) 0; (ch = *s1); s1++) {
		if (ch == c)
	    		s = (char *) s1;

    	}
	return s;
}





