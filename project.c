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
#include <stdio.h>
#include <stdlib.h>
#include "string_lib.h"
#include <sys/types.h> /* for open() */
#include <sys/stat.h> /* for open() */
#include <fcntl.h> /* for open() */
#include <unistd.h> /* for read() */
#include <errno.h> /* for using errno and perror */
#include <ctype.h>
#include <string.h>
char *makestring(char []);
enum function{STPCPY1, STRCAT1, STRCHR1, STRCMP1, STRCOLL1, STRCPY1, STRCSPN1, STRDUP1, STRFRY1, STRLEN1, STRNCAT1, STRNCMP1, STRNCPY, STRPBRK1, STRRCHR1, STRSEP1, STRSPN1, STRSTR1, STRTOK1, STRXFRM1, STPNCPY1, MEMCPY1, STRCASECMP1, STRNCASECMP1, INDEX1, RINDEX1};

typedef struct data{
	int testnum;
	char s1[1024], s2[1024];
	char s3[1024];
}data;

int main(int argc, char *argv[]){
	int i = 0, l;
	int len;
	char *ans;
	char *s;
	FILE *fd;


	data str[50];
	if (argc != 2){
		printf("usage: ./test1 <filename1> \n" );
		perror("failed\n");
		return errno;
	}
	
	fd = fopen(argv[1], "r");
	
	if ( fd == NULL){
		perror("bad address\n");
		return errno;
	}
	while ( i <= 50){	
		fscanf (fd, "%d", &str[i].testnum);
		printf("Entering CASE\n");
		switch(str[i].testnum){ 
			
			case STRCAT1:
				{
				printf("CASE 1 : STRCAT1\n");
				fscanf(fd, "%s", str[i].s1);
				char *t = strtok1(str[i].s1, "\t");
				printf("s1 : %s\n", t);
				
				printf("check 1\n");
				fscanf(fd, "%s", str[i].s2);
				char *t1 = strtok1(str[i].s2, "\t");
				printf("s2 : %s\n", t1);

				printf("check2\n");
				fscanf(fd, "%s", str[i].s3);
				char *ans = strtok1(str[i].s3, "\t");
				printf("Test result : %s\n",ans);

				strcat1(str[i].s1, str[i].s2);
				if (strcmp1(str[i].s1, ans))
					printf("Test qualified\n");				
				else
					printf("Test failed\n\n");
				break;
			}
			case STRCPY1:
				{
				printf("CASE 5 : STRCPY\n");
				fscanf(fd, "%s", str[i].s1);
				char *t2 = strtok1(str[i].s1, "\t");
				printf("s1 : %s\n", t2);
				
				printf("check1\n");
				fscanf(fd, "%s", str[i].s2);
				char *t3 = strtok1(str[i].s2, "\t");
				printf("s2 :  %s\n", t3);
				
				printf("check2\n");
				fscanf(fd, "%s", str[i].s3);
				char *ans = strtok1(str[i].s3, "\t");
				printf("Test result : %s\n",ans);

				strcpy1(str[i].s1, str[i].s2);
				if (strcmp1(str[i].s1, ans))
					printf("Test qualified\n");				
				else
					printf("Test failed\n\n");
				break;
			}		
			case STRLEN1:
				{
				printf("CASE 9 : STRLEN\n");
				fscanf(fd, "%s", str[i].s1);
				char *t = strtok1(str[i].s1, "\t");
				printf("s1 %s\n", t);
				char *t1 = strtok1(NULL, "\t");
				//char *t2 = strtok1(NULL, "\t");
				fscanf(fd, "%d", &l);		
				len = strlen1 ( str[i].s1);			
				printf("Test result : %d\n", len);
				
				if( l == len)
					printf("Test qualified\n");
				else
					printf("Test failed\n\n");				
				break;
			}
			case STPCPY1:
				{
				printf("CASE 0 : STPCPY\n");
				fscanf(fd, "%s", str[i].s1);
				char *t2 = strtok1(str[i].s1, "\t");
				printf("s1 : %s\n", t2);
				
				printf("check1\n");
				fscanf(fd, "%s", str[i].s2);
				char *t3 = strtok1(str[i].s2, "\t");
				printf("s2 :  %s\n", t3);
				
				printf("check2\n");
				fscanf(fd, "%s", str[i].s3);
				char *ans = strtok1(str[i].s3, "\t");
				printf("Test result : %s\n",ans);

				stpcpy1(str[i].s1, str[i].s2);
				if (strcmp1(str[i].s1, ans))
					printf("Test qualified\n");				
				else
					printf("Test failed\n\n");
				break;
			}		
			
			case STRCMP1:
				{
				printf("CASE 3 : STRCMP1\n");
				fscanf(fd, "%s", str[i].s1);
				char *t = strtok1(str[i].s1, "\t");
				printf("s1 : %s\n", t);
				
				printf("check1\n");
				fscanf(fd, "%s", str[i].s2);
				char *t3 = strtok1(str[i].s2, "\t");
				printf("s2 :  %s\n", t3);

				printf("check2\n");
				fscanf(fd, "%s", str[i].s3);
				char *ans = strtok1(str[i].s3, "\t");
				printf("Test result : %s\n", ans);
				
				int j = strcmp1(str[i].s1, str[i].s2);
				printf("Value of function = j = %d\n", j); 
				
				break;
			}
			case STRCOLL1:
				{
				printf("CASE 4 : STRCOLL1\n");
				fscanf(fd, "%s", str[i].s1);
				char *t = strtok1(str[i].s1, "\t");
				printf("s1 : %s\n", t);
	
				printf("check1\n");
				fscanf(fd, "%s", str[i].s2);
				char *t3 = strtok1(str[i].s2, "\t");
				printf("s2 : %s\n", t3);

				printf("check2\n");
				fscanf(fd, "%s", str[i].s3);
				char *ans = strtok1(str[i].s3, "\t");
				printf("Test result : %s\n", ans);

				int j = strcoll1(str[i].s1, str[i].s2);
				printf("Value of function = j = %d\n", j); 
				
				break;
			}
			case STRCSPN1:
				{
				printf("CASE 6 : STRCSPN1\n");
				fscanf(fd, "%s", str[i].s1);
				char *t = strtok1(str[i].s1, "\t");
				printf("s1 : %s\n", t);	

				printf("check1\n");
				fscanf(fd, "%s", str[i].s2);
				char *t3 = strtok1(str[i].s2, "\t");
				printf("s2 : %s\n", t3);

				printf("check2\n");
				fscanf(fd, "%s", str[i].s3);
				char *ans = strtok1(str[i].s3, "\t");
				printf("Test result : %s\n", ans);

				int j = strcspn1(str[i].s1, str[i].s2);
				printf("Value of function = j = %d\n", j); 
				
				break;
			}
			case STRSPN1:
				{
				printf("CASE 16 : STRSPN1\n");
				fscanf(fd, "%s", str[i].s1);
				char *t = strtok1(str[i].s1, "\t");
				printf("s1 : %s\n", t);	

				printf("check1\n");
				fscanf(fd, "%s", str[i].s2);
				char *t3 = strtok1(str[i].s2, "\t");
				printf("s2 : %s\n", t3);

				printf("check2\n");
				fscanf(fd, "%s", str[i].s3);
				char *ans = strtok1(str[i].s3, "\t");
				printf("Test result : %s\n", ans);

				int j = strspn1(str[i].s1, str[i].s2);
				printf("Value of function = j = %d\n", j); 
				
				break;
			}
			case STRDUP1:
				{
				printf("CASE 7 : STRDUP1\n");
				fscanf(fd, "%s", str[i].s1);
				char *t = strtok1(str[i].s1, "\t");
				printf("s1 : %s\n", t);

				printf("check1\n");
				fscanf(fd, "%s", str[i].s2);
				char *ans = strtok1(str[i].s2, "\t");
				printf("Test result : %s\n", ans);

				char *fun = strdup1(str[i].s1);
				if (strcmp1(fun, ans))
					printf("Test qualified\n");				
				else
					printf("Test failed\n\n");
				break;
			}
			case STRFRY1:
				{
				printf("CASE 8 : STRFRY1\n");
				fscanf(fd, "%s", str[i].s1);
				char *t = strtok1(str[i].s1, "\t");
				printf("s1 : %s\n", t);
	
				strfry1(str[i].s1);
				printf("String became %s:\n", str[i].s1);
				break;
			}
			case STRNCAT1:
				{
				printf("CASE 10 : STRNCAT1\n");
				fscanf(fd, "%s", str[i].s1);
				char *t = strtok1(str[i].s1, "\t");
				printf("s1 : %s\n", t);
	
				printf("check1\n");
				fscanf(fd, "%s", str[i].s2);
				char *t1 = strtok(str[i].s2, "\t");
				printf("s2 : %s\n", t1);

				printf("check2\n");
				fscanf(fd, "%s", str[i].s3);
				char *ans = strtok1(str[i].s3, "\t");
				printf("Test result : %s\n",ans);

				strncat1(str[i].s1, str[i].s2, 8);
				if (strcmp1(str[i].s1, ans))
					printf("Test qualified\n");				
				else
					printf("Test failed\n\n");
				break;
			}
			case STRNCMP1:
				{
				printf("CASE 11 : STRNCMP1\n");
				fscanf(fd, "%s", str[i].s1);
				char *t = strtok1(str[i].s1, "\t");
				printf("s1 : %s\n", t);
	
				printf("check1\n");
				fscanf(fd, "%s", str[i].s2);
				char *t1 = strtok(str[i].s2, "\t");
				printf("s2 : %s\n", t1);

				printf("check2\n");
				fscanf(fd, "%s", str[i].s3);
				char *ans = strtok1(str[i].s3, "\t");
				printf("Test result : %s\n",ans);

				strncmp1(str[i].s1, str[i].s2, 8);
				if (strcmp1(str[i].s1, ans))
					printf("Test qualified\n");				
				else
					printf("Test failed\n\n");
				break;
			}
			case STRNCPY:
				{
				printf("CASE 12 : STRNCPY1\n");
				fscanf(fd, "%s", str[i].s1);
				char *t = strtok1(str[i].s1, "\t");
				printf("s1 : %s\n", t);
	
				printf("check1\n");
				fscanf(fd, "%s", str[i].s2);
				char *t1 = strtok(str[i].s2, "\t");
				printf("s2 : %s\n", t1);

				printf("check2\n");
				fscanf(fd, "%s", str[i].s3);
				char *ans = strtok1(str[i].s3, "\t");
				printf("Test result : %s\n",ans);

				strncpy1(str[i].s1, str[i].s2, 12);
				if (strcmp1(str[i].s1, ans))
					printf("Test qualified\n");				
				else
					printf("Test failed\n\n");
				break;
			}
			case STRPBRK1:
				{
				printf("CASE 13 : STRPBRK1\n");
				fscanf(fd, "%s", str[i].s1);
				char *t = strtok1(str[i].s1, "\t");
				printf("s1 : %s\n", t);
	
				printf("check1\n");
				fscanf(fd, "%s", str[i].s2);
				char *t1 = strtok(str[i].s2, "\t");
				printf("s2 : %s\n", t1);

				printf("check2\n");
				fscanf(fd, "%s", str[i].s3);
				char *ans = strtok1(str[i].s3, "\t");
				printf("Test result : %s\n",ans);

				char *fun = strpbrk1(str[i].s1, str[i].s2);
				if (strcmp1(fun, ans))
					printf("Test qualified\n");				
				else
					printf("Test failed\n\n");
				break;
			}
			case STRRCHR1:
				{
				printf("CASE 14: STRRCHR1\n");
				fscanf(fd, "%s", str[i].s1);
				char *t = strtok1(str[i].s1, "\t");
				printf("s1 : %s\n", t);
	
				printf("check1\n");
				fscanf(fd, "%s", str[i].s2);
				char *ans = strtok1(str[i].s2, "\t");
				printf("Test result : %s\n", ans);
				
				char *ret = strrchr1(str[i].s1, '%');
				char ch = '%';
				printf("String including last occurrence of |%c| is - |%s|\n", ch, ret);
				
				if (strcmp1(ret, ans))
					printf("Test qualified\n");				
				else
					printf("Test failed\n\n");
				break;
			}	
			case STRCHR1:
				{
				printf("CASE 2 : STRCHR1\n");
				fscanf(fd, "%s", str[i].s1);
				char *t = strtok1(str[i].s1, "\t");
				printf("s1 : %s\n", t);
				
				printf("check1\n");
				fscanf(fd, "%s", str[i].s2);
				char *ans = strtok1(str[i].s2, "\t");
				printf("Test result : %s\n", ans);
				
				char *s = strchr1(str[i].s1, '%');
				char ch = '%';
				printf("String including first occurrence of |%c| is - |%s|\n", ch, s);
				if (strcmp1(s, ans))
					printf("Test qualified\n");				
				else
					printf("Test failed\n\n");
				break;
			}
			case STRSEP1:
				{
				printf("CASE 15 : STRSEP1\n");
				fscanf(fd, "%s", str[i].s1);
				char *t = strtok(str[i].s1, "\t");
				printf("s1 : %s\n", t);

				char *t1 = strdup1(t);
				
				printf("check2\n");
				fscanf(fd, "%s", str[i].s2);
				char *ans = strtok1(str[i].s2, "\t");
				printf("Test result : %s\n",ans);

				char *fun = strsep1(&t1, ".");
				if (strcmp1(fun, ans))
					printf("Test qualified\n");				
				else
					printf("Test failed\n\n");
				break;
			}	
			case STRSTR1:
				{
				printf("CASE 17 : STRSTR1\n");
				fscanf(fd, "%s", str[i].s1);
				char *t = strtok1(str[i].s1, "\t");
				printf("s1 : %s\n", t);
	
				printf("check1\n");
				fscanf(fd, "%s", str[i].s2);
				char *t1 = strtok(str[i].s2, "\t");
				printf("s2 : %s\n", t1);

				printf("check2\n");
				fscanf(fd, "%s", str[i].s3);
				char *ans = strtok1(str[i].s3, "\t");
				printf("Test result : %s\n",ans);

				char *fun = strstr1(str[i].s1, str[i].s2);
				if (strcmp1(fun, ans))
					printf("Test qualified\n");				
				else
					printf("Test failed\n\n");
				break;
			}
			/*case STRXFRM1:
				{
				printf("CASE 19 : STRXFRM1\n");
				fscanf(fd, "%s", str[i].s1);
				char *t1 = strtok1(str[i].s1, "\t");
				printf("s1 : %s\n", t1);

				printf("check1\n");
				fscanf(fd, "%s", str[i].s2);
				char *ans = strtok1(str[i].s2, "\t");
				printf("Test result : %s\n",ans);
				char *t;
				printf("check2\n");
				int len = strxfrm1(t, t1, 9);
				printf("Length of string |%s| is: |%d|\n", t, len);
				if (strcmp1(t, ans))
					printf("Test qualified\n\n");				
				else
					printf("Test failed\n\n");
				break;
			}*/
			case STPNCPY1:
				{
				
				printf("CASE 20 : STPNCPY1\n");
				fscanf(fd, "%s", str[i].s1);
				char *t = strtok1(str[i].s1, "\t");
				printf("s1 : %s\n", t);
	
				printf("check1\n");
				fscanf(fd, "%s", str[i].s2);
				char *t1 = strtok(str[i].s2, "\t");
				printf("s2 : %s\n", t1);

				printf("check2\n");
				fscanf(fd, "%s", str[i].s3);
				char *ans = strtok1(str[i].s3, "\t");
				printf("Test result : %s\n",ans);

				stpncpy1(str[i].s1, str[i].s2, 12);
				if (strcmp1(str[i].s1, ans))
					printf("Test qualified\n");				
				else
					printf("Test failed\n\n");
				break;
			}	
			case MEMCPY1:
				{
				printf("CASE 21 : MEMCPY1\n");
				fscanf(fd, "%s", str[i].s1);
				char *t = strtok1(str[i].s1, "\t");
				printf("s1 : %s\n", t);
	
				printf("check1\n");
				fscanf(fd, "%s", str[i].s2);
				char *t1 = strtok(str[i].s2, "\t");
				printf("s2 : %s\n", t1);

				printf("check2\n");
				fscanf(fd, "%s", str[i].s3);
				char *ans = strtok1(str[i].s3, "\t");
				printf("Test result : %s\n",ans);

				memcpy1(str[i].s1, str[i].s2, 13);
				if (strcmp1(str[i].s1, ans))
					printf("Test qualified\n");				
				else
					printf("Test failed\n\n");
				break;
			}			
			case STRCASECMP1:
				{
				printf("CASE 22 : STRCASECMP1\n");
				fscanf(fd, "%s", str[i].s1);
				char *t = strtok1(str[i].s1, "\t");
				printf("s1 : %s\n", t);
	
				printf("check1\n");
				fscanf(fd, "%s", str[i].s2);
				char *t1 = strtok(str[i].s2, "\t");
				printf("s2 : %s\n", t1);

				printf("check2\n");
				fscanf(fd, "%s", str[i].s3);
				char *ans = strtok1(str[i].s3, "\t");
				printf("Test result : %s\n",ans);

				strcasecmp1(str[i].s1, str[i].s2);
				if (strcmp1(str[i].s1, ans))
					printf("Test qualified\n");				
				else
					printf("Test failed\n\n");
				break;
			}			
			case STRNCASECMP1:
				{
				printf("CASE 23 : STRNCASECMP1\n");
				fscanf(fd, "%s", str[i].s1);
				char *t = strtok1(str[i].s1, "\t");
				printf("s1 : %s\n", t);
	
				printf("check1\n");
				fscanf(fd, "%s", str[i].s2);
				char *t1 = strtok(str[i].s2, "\t");
				printf("s2 : %s\n", t1);

				printf("check2\n");
				fscanf(fd, "%s", str[i].s3);
				char *ans = strtok1(str[i].s3, "\t");
				printf("Test result : %s\n",ans);

				strncasecmp1(str[i].s1, str[i].s2, 6);
				if (strcmp1(str[i].s1, ans))
					printf("Test qualified\n");				
				else
					printf("Test failed\n\n");
				break;
			}				
			case INDEX1:
				{
				printf("CASE 24: INDEX1\n");
				fscanf(fd, "%s", str[i].s1);
				char *t = strtok1(str[i].s1, "\t");
				printf("s1 : %s\n", t);
	
				printf("check1\n");
				fscanf(fd, "%s", str[i].s2);
				char *ans = strtok1(str[i].s2, "\t");
				printf("Test result : %s\n", ans);
				
				char *ret = index1(str[i].s1, '%');
				char ch = '%';
				printf("String after |%c| is - |%s|\n", ch, ret);
				
				if (strcmp1(ret, ans))
					printf("Test qualified\n");				
				else
					printf("Test failed\n\n");
				break;
			}	
			case RINDEX1:
				{
				printf("CASE 25 : RINDEX1\n");
				fscanf(fd, "%s", str[i].s1);
				char *t = strtok1(str[i].s1, "\t");
				printf("s1 : %s\n", t);
				
				printf("check1\n");
				fscanf(fd, "%s", str[i].s2);
				char *ans = strtok1(str[i].s2, "\t");
				printf("Test result : %s\n", ans);
				
				char *s = rindex1(str[i].s1, '%');
				char ch = '%';
				printf("String after |%c| is - |%s|\n", ch, s);
				if (strcmp1(s, ans))
					printf("Test qualified\n");				
				else
					printf("Test failed\n\n");
				break;
			}
			case STRTOK1:
				{
				printf("CASE 18 : STRTOK1\n");
				fscanf(fd, "%s", str[i].s1);
				char *t = strtok1(str[i].s1, "\t");
				printf("s1 : %s\n", t);
				
				printf("check1\n");
				fscanf(fd, "%s", str[i].s2);
				char *ans = strtok1(str[i].s2, "\t");
				printf("Test result : %s\n", ans);	
				
				if (strcmp1(t, ans))
					printf("Test qualified\n");				
				else
					printf("Test failed\n\n");
				break;
			}	
			case 100 :
				{
				printf("Done with cases : Endoftest :)\n");
			}	
					
								
		}
		printf("Case Seen\n\n");
		
		i++;
	}
		printf("THE END\n");
		return 0;
		
}		

char *makestring(char arr[1024]){

	
	int l = strlen(arr);
	
	arr[l] = '\0';
	
	return arr;
}
	

 





