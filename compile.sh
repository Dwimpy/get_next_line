#!/bin/sh
for i in *.c
do
	echo "Compiling $i"
	gcc -I ../get_next_line -c $i -fsanitize=address -fsanitize=leak -Wall -Werror -Wextra
done
for i in *.o
do
	chmod 777 $i
done
echo "Compilation Successful."
DIRS=$(find . -type f -name "*.o" | tr '\n' ' ' | sed 's/\.\///g')

gcc -o test ${DIRS} -fsanitize=address -fsanitize=leak -Wall -Werror -Wextra

echo "Test executable created."