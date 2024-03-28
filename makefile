CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LIBS = -lm

SRCS = main.c mastermind.c file_handling.c color_library.c
OBJS = $(SRCS:.c=.o)
TARGET = mastermind

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    $(RM) $(TARGET) $(OBJS)
