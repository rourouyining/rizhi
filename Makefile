CC=gcc

obj=loopfile.o

LIB= -L./ -lmodule_std
CFLAGS= -Wall -g 
INCLUDE=

target=loopfile.so

all:$(obj)
	$(CC) -shared -fPIC $^ -o $(target) $(LIB)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ 
