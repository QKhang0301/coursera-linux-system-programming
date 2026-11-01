CC := gcc
CFLAGS := -Wall -g

TARGET := test_execl test_fork
SRC := test_execl.c test_fork.c
OBJ := $(SRC:.c=.o)

all : $(TARGET)

test_execl : test_execl.o
	$(CC) $(CFLAGS) $< -o $@

test_fork : test_fork.o
	$(CC) $(CFLAGS) $< -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(TARGET) $(OBJ)

.PHONY: all clean
