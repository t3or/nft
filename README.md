*This project has been created as part of the 42 curriculum by
yamouqin.*

# Libft

## Description

Libft is a C library that recreates a selection of standard C library
functions and adds string, memory, output, and linked-list utilities.
Its goal is to build a reusable set of low-level functions while
practising memory management, pointers, and data structures.

The library is built as `libft.a`. It contains the mandatory functions
and, when requested, the bonus linked-list functions.

## Instructions

### Build

``` sh
make        # mandatory functions
make bonus  # mandatory + bonus functions
make clean  # remove object files
make fclean # remove object files and libft.a
make re     # rebuild the mandatory library
```

The Makefile must compile with `cc -Wall -Wextra -Werror` and create
`libft.a` at the repository root.

### Inspect the library

`libft.a` is a static archive: it groups the compiled object files
(`*.o`) into one library. It is not an executable. When a program links
against `-lft`, the linker uses the archive to find the required code.

```sh
ar -t libft.a                 # list object files in the archive
ar -tv libft.a                # list members with details
nm libft.a                    # list symbols from every object file
nm -g --defined-only libft.a  # list globally defined symbols
nm -u libft.a                 # list undefined symbols (external dependencies)
nm -A libft.a                 # show which object file contains each symbol
file libft.a                  # identify the archive format
```

Common `nm` symbol types:

- `T`: globally defined function (code).
- `t`: locally defined function (not globally exported).
- `U`: undefined symbol; it must be provided elsewhere at link time.
- `D` / `d`: initialized global / local data.
- `B` / `b`: uninitialized global / local data.
- `R` / `r`: read-only global / local data.

For this project, `nm -g --defined-only libft.a` should list the
exported `ft_` functions. Use `nm -u libft.a` to inspect external
dependencies; symbols such as `malloc`, `free`, or `write` may be
expected where the subject permits them. The archive can also contain
an index that helps the linker locate symbols efficiently.

### Use

Include `libft.h` and link the library:

``` sh
cc -Wall -Wextra -Werror main.c -I. -L. -lft
```

### Requirements

-   Written in C and compliant with the 42 Norm.
-   No global variables.
-   Source files and `libft.a` are placed at the repository root.
-   The archive is created with `ar`.
-   Allocated memory must be freed by the caller when no longer needed.
-   The mandatory and bonus parts are evaluated separately.

## Library functions

### Part 1 --- Libc reimplementations

These functions use the `ft_` prefix and reproduce the required
standard-function behaviour. They must not call external functions.

  -----------------------------------------------------------------------
  Function                            Purpose
  ----------------------------------- -----------------------------------
  `ft_isalpha`                        Tests whether a character is an
                                      alphabetic letter.

  `ft_isdigit`                        Tests whether a character is a
                                      decimal digit.

  `ft_isalnum`                        Tests whether a character is
                                      alphanumeric.

  `ft_isascii`                        Tests whether a value is in the
                                      ASCII range.

  `ft_isprint`                        Tests whether a character is
                                      printable.

  `ft_toupper`                        Converts a lowercase letter to
                                      uppercase.

  `ft_tolower`                        Converts an uppercase letter to
                                      lowercase.

  `ft_strlen`                         Returns the length of a string,
                                      excluding its terminating null
                                      byte.

  `ft_memset`                         Fills a memory area with a byte
                                      value.

  `ft_bzero`                          Sets a memory area to zero bytes.

  `ft_memcpy`                         Copies a specified number of bytes
                                      between non-overlapping memory
                                      areas.

  `ft_memmove`                        Copies bytes while safely handling
                                      overlapping memory areas.

  `ft_memchr`                         Finds the first occurrence of a
                                      byte in a memory area.

  `ft_memcmp`                         Compares two memory areas byte by
                                      byte.

  `ft_strlcpy`                        Copies a string into a size-limited
                                      destination and returns the source
                                      length.

  `ft_strlcat`                        Appends a string to a size-limited
                                      destination and returns the length
                                      it tried to create.

  `ft_strchr`                         Finds the first occurrence of a
                                      character in a string.

  `ft_strrchr`                        Finds the last occurrence of a
                                      character in a string.

  `ft_strncmp`                        Compares at most a specified number
                                      of characters in two strings.

  `ft_strnstr`                        Finds a substring within a string,
                                      searching no more than the
                                      specified length.

  `ft_atoi`                           Converts the initial numeric
                                      portion of a string to an integer.

  `ft_calloc`                         Allocates memory for an array and
                                      initializes its bytes to zero.

  `ft_strdup`                         Allocates and returns a duplicate
                                      of a string.
  -----------------------------------------------------------------------

`ft_calloc` and `ft_strdup` use `malloc`. The subject requires
`ft_calloc` to return a freeable pointer when either allocation
dimension is zero.

### Part 2 --- Additional functions

  -----------------------------------------------------------------------
  Function                Purpose                 External functions
  ----------------------- ----------------------- -----------------------
  `ft_substr`             Allocates a substring   `malloc`
                          starting at an index,   
                          up to a maximum length. 

  `ft_strjoin`            Allocates the           `malloc`
                          concatenation of two    
                          strings.                

  `ft_strtrim`            Copies a string after   `malloc`
                          removing characters     
                          from a given set at     
                          both ends.              

  `ft_split`              Splits a string by a    `malloc`, `free`
                          delimiter into          
                          independently           
                          allocated,              
                          null-terminated         
                          strings.                

  `ft_itoa`               Converts an integer to  `malloc`
                          an allocated string,    
                          including negative      
                          values.                 

  `ft_strmapi`            Creates a new string by `malloc`
                          applying a function to  
                          each character and its  
                          index.                  

  `ft_striteri`           Applies a function to   None
                          each character and its  
                          index, passing the      
                          character by address so 
                          it can be modified.     

  `ft_putchar_fd`         Writes one character to `write`
                          a file descriptor.      

  `ft_putstr_fd`          Writes a string to a    `write`
                          file descriptor.        

  `ft_putendl_fd`         Writes a string         `write`
                          followed by a newline   
                          to a file descriptor.   

  `ft_putnbr_fd`          Writes an integer to a  `write`
                          file descriptor.        
  -----------------------------------------------------------------------

Functions that allocate memory return `NULL` when allocation fails, as
specified by the subject. The caller must free returned allocations.

### Part 3 --- linked lists

The bonus part uses this node structure:

``` c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

`content` stores the node's data; `next` points to the following node or
`NULL`.

  -----------------------------------------------------------------------
  Function                Purpose                 External functions
  ----------------------- ----------------------- -----------------------
  `ft_lstnew`             Allocates a node,       `malloc`
                          stores the supplied     
                          content, and            
                          initializes `next` to   
                          `NULL`.                 

  `ft_lstadd_front`       Adds a node at the      None
                          beginning of a list.    

  `ft_lstsize`            Counts the nodes in a   None
                          list.                   

  `ft_lstlast`            Returns the last node   None
                          of a list.              

  `ft_lstadd_back`        Adds a node at the end  None
                          of a list.              

  `ft_lstdelone`          Applies a               `free`
                          content-deletion        
                          function and frees one  
                          node, without deleting  
                          its successor.          

  `ft_lstclear`           Deletes a node and all  `free`
                          following nodes, then   
                          sets the list pointer   
                          to `NULL`.              

  `ft_lstiter`            Applies a function to   None
                          the content of every    
                          node.                   

  `ft_lstmap`             Applies a function to   `malloc`, `free`
                          each node's content and 
                          builds a new list; uses 
                          the deletion function   
                          if creating the new     
                          list fails.             
  -----------------------------------------------------------------------

## Resources

-   42 **Libft** subject, version 19.3.
-   The relevant C library manual pages (`man 3`), including `strlen`,
    `memcpy`, `memmove`, `calloc`, and string functions.
-   C language and library references: [cppreference ---
    C](https://en.cppreference.com/w/c).

AI assistance was used to help organize and edit this README. The
project requirements and function descriptions are based on the 42
subject; implementation, testing.
