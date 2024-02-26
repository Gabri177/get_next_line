# Get_Next_Line Project

## Introduction

`get_next_line` is a coding project from the 42 school, aimed at developing a function that allows reading a line from a file descriptor. This project challenges students to create efficient and memory-leak free code, enhancing their understanding of static variables in C, dynamic memory allocation, and file operations.

## Objective

The main objective of this project is to create a function, `get_next_line`, that returns a line read from a file descriptor. This function must manage memory efficiently and handle multiple file descriptors simultaneously, providing a deeper understanding of system programming concepts in C.

## Technologies & Languages Used

- **Language:** C
- **Key Concepts:** Dynamic Memory Allocation, Static Variables, File Descriptors
- **Compilation:** GCC with flags `-Wall -Wextra -Werror`
- **Supported OS:** Unix-based systems

## Features

- Reads lines efficiently from a file descriptor.
- Manages multiple file descriptors.
- Prevents memory leaks through meticulous memory management.
- Configurable buffer size at compile time.

## Usage

To integrate `get_next_line` in your project:

1. Include the `get_next_line.h` header file in your source file.
2. Call `get_next_line` with a valid file descriptor to read a line from a file or input stream.

Example code snippet:

```c
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc > 1)
    {
        fd = open(argv[1], O_RDONLY);
        while ((line = get_next_line(fd)) != NULL)
        {
            printf("%s", line);
            free(line);
        }
        close(fd);
    }
    return (0);
}
```
