CFLAGS = -Wall -Werror -g -std=c99

CC_C = $(CROSS_TOOL)gcc

$(TARGETS):
	$(CC_C) $(CFLAGS) $@.c -o $@

smartlistWerror: smartlist.o test.c
	gcc smartlist.c test.c -o test && ./test

smartlistWerror: smartlist.o test.c
	gcc $(CFLAGS) smartlist.c test.c -o test && ./test

clean:
	rm -rf $(TARGETS)