all: project test1.txt
project: string_lib.o project.o
		cc string_lib.o project.o -o project
project.o: project.c
		cc -c project.c
string_lib.o: string_lib.c string_lib.h
		cc -c string_lib.c
clean:
		rm *.o
