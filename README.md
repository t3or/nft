# Libft

Libft is the first project in the 42 Common Core. It is a personal C library
that reimplements a selection of standard C library functions and adds utility
functions for strings and linked lists. The library can be reused in later 42
projects.

## Contents

- **Mandatory part:** character checks and conversions, memory operations,
  string operations, allocation, and file-descriptor output functions.
- **Bonus part:** singly linked-list creation, traversal, deletion, and mapping
  functions.
- **`libft.h`:** public function prototypes and the `t_list` definition.

## Build

Build the mandatory library:

```sh
make
```

Build the mandatory and bonus functions:

```sh
make bonus
```

Both targets create the static library `libft.a` in the project root.

## Use in a project

Include `libft.h` in your source files and link the library when compiling:

```sh
cc -Wall -Wextra -Werror -I/path/to/libft \
    main.c -L/path/to/libft -lft
```

Replace `/path/to/libft` with the directory containing `libft.h` and
`libft.a`.

## Inspect object files and the static library

A `.c` file is source code, not a statically linked binary. Compile it to an
object file (`.o`) to inspect its ELF headers and symbols:

```sh
cc -Wall -Wextra -Werror -c ft_strlen.c -o /tmp/ft_strlen.o
readelf -h -S /tmp/ft_strlen.o       # ELF header and sections
readelf -s /tmp/ft_strlen.o          # symbol table
nm -g --defined-only /tmp/ft_strlen.o
nm -u /tmp/ft_strlen.o               # symbols the object needs from elsewhere
```

Inspect the members and symbols in `libft.a` without extracting its object
files:

```sh
ar t libft.a                         # list archive members
ar tv libft.a                        # list members with details
nm -A -g --defined-only libft.a      # defined global symbols, labeled by member
```

To inspect an individual object from the archive with `readelf`, extract it
into a separate directory first:

```sh
mkdir -p /tmp/libft-inspect
cd /tmp/libft-inspect
ar x /path/to/libft/libft.a ft_strlen.o
readelf -h -S -s ft_strlen.o
```

After linking an executable against `libft.a` as in the previous example, check
the executable's dependencies and dynamic symbols with:

```sh
readelf -d ./a.out                    # dynamic section, if present
nm -D ./a.out                         # dynamic symbols, if present
nm ./a.out | grep ' ft_strlen$'       # look for the linked library function
```

Linking with `-L... -lft` incorporates the needed archive members, but does not
make the whole executable fully static; the system libraries may still be
dynamic. A fully static executable requires toolchain support and an explicit
`-static` linker option.

## Make targets

| Target | Description |
| --- | --- |
| `make` or `make all` | Build the mandatory library. |
| `make bonus` | Build the mandatory and linked-list bonus functions. |
| `make clean` | Remove object files. |
| `make fclean` | Remove object files and `libft.a`. |
| `make re` | Clean and rebuild the mandatory library. |

## Function groups

**Character and conversion:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`,
`ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`, `ft_atoi`, `ft_itoa`.

**Memory:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`,
`ft_memcmp`, `ft_calloc`.

**Strings:** `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`,
`ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`, `ft_substr`,
`ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri`.

**File-descriptor output:** `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`,
`ft_putnbr_fd`.

**Bonus linked lists:** `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`,
`ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`,
`ft_lstmap`.

## Notes

- Functions that allocate memory return `NULL` if allocation fails. The caller
  is responsible for freeing allocated memory.
- List deletion functions call the supplied `del` callback to dispose of
  content.
- This README documents the project and build usage; check the current 42
  subject and evaluation requirements for the exact rules applicable to your
  campus and project version.
