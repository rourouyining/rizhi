CC=gcc

obj=loopfile.o

LIB= -L./ -lmodule_std
CFLAGS= -Wall -g -fPIC
INCLUDE=

target=loopfile.so

all:$(obj)
	$(CC) -shared  $^ -o $(target) $(LIB)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ 
