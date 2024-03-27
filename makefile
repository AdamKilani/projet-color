CC=gcc
CFLAGS=-Wall -Wextra -std=c99

SRCS=main.c mastermind.c
OBJS=$(SRCS:.c=.o)

EXEC=mastermind

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(EXEC)
