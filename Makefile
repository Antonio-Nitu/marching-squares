CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -Iheaders
EXEC = marching_squares
SRCS = main.c $(wildcard modules/*.c)
OBJS = $(SRCS:.c=.o)

all: build

build: $(EXEC)

$(EXEC): $(OBJS)
	@echo "Linking..."
	$(CC) $(OBJS) -o $(EXEC)
	@echo "Build finished. Executable is '$(EXEC)'."

%.o: %.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning up..."
	rm -f $(EXEC) $(OBJS)
	@echo "Cleanup complete."

.PHONY: all build clean
