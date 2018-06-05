CFLAGS = -ansi -pedantic -Wall
CC = gcc

all: project;

	$(CC) $(CFLAGS) -o project main.o sysdate.o date.o errors.o 

main.o: main.c date.h sysdate.h erorrs.h 
	$(CC) $(CLFAGS) -o main.o -c main.c

sysdate.o: sysdate.c sysdate.h
	$(CC) $(CFLAGS) -o sysdate.o -c sysdate.c

date.o: date.c date.h
	$(CC) $(CFLAGS) -o date.o -c date.c

errors.o: errors.c errors.h
	$(CC) $(CFLAGS) -o errors.o -c errors.c