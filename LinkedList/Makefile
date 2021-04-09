CFLAGS = -Wall -g -std=c99
CC = clang
SRCS = smartlist.c test.c
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

output: $(OBJS)
	$(CC) $(CFLAGS) -o test $(OBJS) && ./test

clean:
	rm -rf *.o
