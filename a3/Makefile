# Makefile for the filter program

FLAGS= -Wall -g -std=gnu99

all : copy

copy : copy.o bitmap.o
	gcc ${FLAGS} -o $@ $^

# Separately compile each C file

# Ensure that the 
bitmap.o : bitmap.h
copy.o : bitmap.h


%.o : %.c 
	gcc ${FLAGS} -c $<


clean :
	-rm *.o copy
