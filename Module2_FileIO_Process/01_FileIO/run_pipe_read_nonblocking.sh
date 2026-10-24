#!/bin/sh
#compile the readfile.c
make
#remove any pipe file
rm -f pipe
#create new pipe
mkfifo pipe

#Open to read the pipe, and put this operation into the background
#This will prevent writing the pipe from getting block
echo < pipe &

#Write to the pipe, but don't actually write anything
#This will cause EAGAIN when using reafile in non-blocking mode
exec 3>pipe

echo "Attempt reading a pipe in nonblocking mode"
./readfile pipe nonblock
