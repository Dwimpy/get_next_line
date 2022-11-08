#!/bin/sh
for i in *.c
do
	echo "Compiling $i"
	gcc -c $i -I ../get_next_line
done
for i in *.o
do
	chmod +444 $i
done
echo "Compilation Successful."
DIRS=$(find . -type f -name "*.o" | tr '\n' ' ' | sed 's/\.\///g')

gcc -o test ${DIRS}

echo "Test executable created."