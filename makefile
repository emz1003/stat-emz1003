all: main.o stat.o
	gcc -o program main.o stat.o
main.o: main.c stat.h
	gcc -c main.c stat.h
stat.o: stat.c stat.h
	gcc -c stat.c stat.h
