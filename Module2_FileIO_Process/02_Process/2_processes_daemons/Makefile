CC := gcc
CFLAGS := -Wall -g

TARGET := get_uid_gid
SRC := get_uid_gid.c
OBJ := $(SRC:.c=.o)

all: $(TARGET)

get_uid_gid : get_uid_gid.o
	$(CC) $(CFLAGS) $< -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $<


clean:
	rm -rf $(TARGET) $(OBJ)

.PHONY : all clean