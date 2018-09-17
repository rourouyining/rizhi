CC=gcc

obj=loopfile.o

LIB= -L./module_std.so
CFLAGS= -Wall -g 
INCLUDE=

target=loopfile.so

all:$(obj)
	$(CC) -shared -fpic $^ -o $(target) $(LIB)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ 
