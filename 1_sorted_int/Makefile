# http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

CC=gcc
CFLAGS=-Wall -std=c99 -g
LDFLAGS=-lpthread
DEPS=

all: cbuffer_test

cbuffer_test: cbuffer_test.c $(DEPS)
	$(CC) $(CFLAGS) cbuffer_test.c cbuffer.c -o cbuffer_test $(LDFLAGS)

clean:
	rm cbuffer_test

