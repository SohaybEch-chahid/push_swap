*This project has been created as part of the 42 curriculum by sech-cha.*

# Libft

## Description

Libft is a custom C library developed as part of the 42 curriculum. The goal of this project is to recreate a set of standard C library functions and implement additional utility functions to build a reusable library.

This project helps develop a deeper understanding of C programming, memory management, pointers, strings, data structures, and linked lists.

The library is compiled into a static library named `libft.a`, which can be linked to other C programs.

## Instructions

### Requirements

- A C compiler such as `cc`.
- GNU Make.
- A Unix-like operating system.

### Compilation

Compile the library using the Makefile:

```bash
make
```

This generates the static library `libft.a`.

To remove object files:

```bash
make clean
```

To remove object files and the compiled library:

```bash
make fclean
```

To rebuild the library from scratch:

```bash
make re
```

### Using the library

Include the header file in your C source code:

```c
#include "libft.h"
```

Compile your program and link it against the library:

```bash
cc -Wall -Wextra -Werror main.c libft.a -o program
```

Run the executable:

```bash
./program
```

The source files and `libft.h` must be available when compiling your program.

## Library Contents

Libft contains re-implementations of standard C library functions and additional utility functions.

### 1. Character Classification and Conversion

These functions check character properties or convert character case.

- `ft_isalpha`: checks whether a character is alphabetic.
- `ft_isdigit`: checks whether a character is a digit.
- `ft_isalnum`: checks whether a character is alphanumeric.
- `ft_isascii`: checks whether a character belongs to the ASCII range.
- `ft_isprint`: checks whether a character is printable.
- `ft_toupper`: converts a lowercase letter to uppercase.
- `ft_tolower`: converts an uppercase letter to lowercase.

### 2. String Functions

These functions perform operations on strings.

- `ft_strlen`: calculates the length of a string.
- `ft_strlcpy`: copies a string with a specified size limit.
- `ft_strlcat`: appends a string with a specified size limit.
- `ft_strchr`: searches for a character in a string.
- `ft_strrchr`: searches for the last occurrence of a character.
- `ft_strncmp`: compares two strings up to a specified number of characters.
- `ft_strnstr`: searches for a substring within a string.
- `ft_strdup`: duplicates a string using dynamic memory allocation.
- `ft_substr`: extracts a substring.
- `ft_strjoin`: concatenates two strings.
- `ft_strtrim`: removes specified characters from the beginning and end of a string.
- `ft_split`: splits a string using a delimiter.
- `ft_strmapi`: applies a function to each character and creates a new string.
- `ft_striteri`: applies a function to each character in place.

### 3. Memory Functions

These functions manipulate memory areas.

- `ft_memset`: fills a memory area with a specified byte.
- `ft_bzero`: sets a memory area to zero.
- `ft_memcpy`: copies bytes between non-overlapping memory areas.
- `ft_memmove`: copies bytes while handling overlapping memory areas.
- `ft_memchr`: searches for a byte in a memory area.
- `ft_memcmp`: compares two memory areas.
- `ft_calloc`: allocates zero-initialized memory.

### 4. Conversion Functions

- `ft_atoi`: converts a string to an integer.
- `ft_itoa`: converts an integer to a string.

### 5. File Descriptor Functions

These functions write characters, strings, and numbers to a specified file descriptor.

- `ft_putchar_fd`: writes a character.
- `ft_putstr_fd`: writes a string.
- `ft_putendl_fd`: writes a string followed by a newline.
- `ft_putnbr_fd`: writes an integer.

### 6. Linked List Functions

The linked list functions operate on the `t_list` structure defined in `libft.h`. Each node contains a content pointer and a pointer to the next node.

- `ft_lstnew`: creates a new list node.
- `ft_lstadd_front`: adds a node to the beginning of a list.
- `ft_lstsize`: counts the nodes in a list.
- `ft_lstlast`: returns the last node.
- `ft_lstadd_back`: adds a node to the end of a list.
- `ft_lstdelone`: deletes one node using a supplied deletion function.
- `ft_lstclear`: deletes an entire list.
- `ft_lstiter`: applies a function to every node's content.
- `ft_lstmap`: creates a new list by applying a function to each node's content.

**Note:** The exact function list must match the functions included in your submitted project and the requirements of your Libft subject.

## Resources

### Documentation and references

- [42 School](https://42.fr/) — information about the 42 curriculum.
- [Linux man-pages](https://man7.org/linux/man-pages/) — documentation for standard C library functions and system calls.
- [cppreference: C library](https://en.cppreference.com/w/c/header) — reference documentation for C standard library headers.
- [GNU Make Manual](https://www.gnu.org/software/make/manual/) — documentation for Makefiles and build automation.
- [C Programming: A Modern Approach](https://www.knking.com/books/c2/) — a reference for C programming concepts.

### AI usage

AI tools were used as learning assistance during this project, including:

- Explaining C programming concepts such as pointers, memory allocation, strings, and linked lists.
- Helping understand compiler errors and debug implementation issues.
- Reviewing code and discussing edge cases and memory management.
- Assisting with the organization and documentation of the library.

The project was developed as a learning exercise. The author is responsible for understanding, reviewing, testing, and validating the submitted code and ensuring compliance with the 42 subject and evaluation rules.
