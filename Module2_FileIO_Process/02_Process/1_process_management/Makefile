CC := gcc
CFLAGS := -Wall -g

TARGET := test_execl test_fork fork_execl_wait wait
SRC := test_execl.c test_fork.c fork_execl_wait.c wait.c
OBJ := $(SRC:.c=.o)

all : $(TARGET)

wait : wait.o
	$(CC) $(CFLAGS) $< -o $@

test_execl : test_execl.o
	$(CC) $(CFLAGS) $< -o $@

test_fork : test_fork.o
	$(CC) $(CFLAGS) $< -o $@

fork_execl_wait : fork_execl_wait.o
	$(CC) $(CFLAGS) $< -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(TARGET) $(OBJ)

.PHONY: all clean
