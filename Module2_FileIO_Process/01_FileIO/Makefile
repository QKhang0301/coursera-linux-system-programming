CC := gcc
CFLAGS := -Wall -g

TARGET := readfile
SRC := readfile.c
OBJ := $(SRC:.c=.o)

all: $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(TARGET) $(OBJ)

.PHONY: all clean