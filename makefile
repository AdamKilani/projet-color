# Makefile for mastermind project

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Source and binary directories
SRCDIR = src
BINDIR = bin

# All source files
SRC = $(wildcard $(SRCDIR)/*.c)

# All object files
OBJ = $(SRC:$(SRCDIR)/%.c=$(BINDIR)/%.o)

# Executable name
EXECUTABLE = mastermind

# Targets
.PHONY: all clean

# Default target to build the executable
all: $(EXECUTABLE)

# Build the executable using the object files
$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compile a source file into an object file
$(BINDIR)/%.o: $(SRCDIR)/%.c | $(BINDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Create the binary directory
$(BINDIR):
	mkdir -p $(BINDIR)

# Clean target
clean:
	rm -rf $(BINDIR) $(EXECUTABLE)
