CC := gcc
CFLAGS := -Wall -g

TARGET := readfile sparsefile
SRC := readfile.c sparsefile.c
OBJ := $(SRC:.c=.o)

all: $(TARGET)

# $(TARGET) : $(OBJ)
# 	$(CC) $(CFLAGS) $^ -o $@
readfile: readfile.o
	$(CC) $(CFLAGS) readfile.o -o readfile

sparsefile : sparsefile.o
	$(CC) $(CFLAGS) sparsefile.o -o sparsefile

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(TARGET) $(OBJ)

.PHONY: all clean