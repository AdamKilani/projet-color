# Use CFLAGS to store compiler flags and CXXFLAGS for C++ compiler flags
CFLAGS=-Wall -Wextra -std=c99 -pedantic -O2

# Add a variable for the source directory
SRC_DIR=src

# Add a variable for the object directory
OBJ_DIR=obj

# Use $(SRCS:%=$(OBJ_DIR)/%.o) instead of $(OBJS) to avoid repeating the rule
# for creating object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Add VPATH to search for source files in the source directory
VPATH=$(SRC_DIR)

SRCS=main.c mastermind.c
OBJS=$(SRCS:.c=$(OBJ_DIR)/%.o)

EXEC=mastermind

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS) $(EXEC)

