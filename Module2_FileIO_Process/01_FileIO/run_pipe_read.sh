#!/bin/sh
#clean and recompile
make clean
make
# remove any pipe file and create new
rm -f pipe
mkfifo pipe
# reading the pipe, will be blocked
# to unblock run command \"echo "hi" > pipe \" in another terminal to unblock
./readfile pipe