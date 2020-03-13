# http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

CC=gcc
CFLAGS=-Wall  -std=c99 -g
LDFLAGS=
DEPS=

all: test_buffer 

test_buffer: test_buffer.c $(DEPS)
	$(CC) $(CFLAGS) test_buffer.c buffer.c $(LDFLAGS) -o test_buffer

clean:
	rm test_buffer
