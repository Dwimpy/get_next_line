Get Next Line - 42 Project
==========================

This project aims to read a line of text from a specified file descriptor and return a pointer to the line. 
The function `get_next_line()` allows reading a file descriptor one line at a time, making it easier to handle 
and manipulate the text. The function returns the line that was read, including the terminating `\n` character,
except when the end of the file was reached and does not end with a `\n` character.

The function is prototyped as `char *get_next_line(int fd)` and is included in the header file `get_next_line.h`. 
The turn-in files include the implementation of the function in `get_next_line.c`, along with any necessary helper functions in `get_next_line_utils.c`.

The function takes an integer file descriptor value `fd` as a parameter and returns a pointer to the line read from the file descriptor. 
If there is nothing else to read or if an error occurred, the function returns NULL.

The function uses external functions `read()`, `malloc()`, and `free()`. To define the buffer size for `read()`, 
the option `-D BUFFER_SIZE=n` must be added to the compiler call. The buffer size value will be modified by 
peer-evaluators and the Moulinette in order to test the code.

The implementation of `get_next_line()` allows repeated calls to read the text file pointed to by the file descriptor,
one line at a time. The function works as expected when reading a file or reading from the standard input.

In conclusion, `get_next_line()` is a useful function for reading text from a file descriptor one line at a time. 
Its implementation and the accompanying helper functions in this project meet the requirements and specifications set forth in the project instructions.

## Compilation:
```bash
  # Compiles with no bonus and creates gnl.a static library
  make 
  # Compiles the bonus and creates the gnl_bonus.a static library
  make bonus
```
## Usage:
  > Link the static libraries created with your project and 
  > call get_next_line() on an open file descriptor.
