# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iheaders

# Source files
SRC = main.c $(wildcard modules/*.c)
OBJ = $(SRC:.c=.o)

# Target executable
TARGET = marching_squares

# Default rule
all: $(TARGET)

# Link object files into the final binary
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
ifeq ($(OS),Windows_NT)
	del /Q $(subst /,\,$(OBJ)) $(TARGET) 2>nul || exit 0
else
	rm -f $(OBJ) $(TARGET)
endif


# Phony targets
.PHONY: all clean
