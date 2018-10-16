# choose your compiler
CC=gcc
#CC=gcc -Wall

mysh: watchmail.o sh.o get_path.o main.c
	$(CC) -g main.c watchmail.o sh.o get_path.o -o mysh -lpthread
#	$(CC) -g main.c watchmail.o sh.o get_path.o bash_getcwd.o -o mysh -lpthread

sh.o: sh.c sh.h
	$(CC) -g -c sh.c

get_path.o: get_path.c get_path.h
	$(CC) -g -c get_path.c

watchmail.o: watchmail.c watchmail.h
	$(CC) -g -c watchmail.c

clean:
	rm -rf watchmail.o sh.o get_path.o mysh
