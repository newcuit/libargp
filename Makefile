VPATH := .
SRC := test.c libargp.c
CFLAGS += -I.

test: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $@

clean:
	-@rm -rf test
