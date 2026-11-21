# get_next_line

A buffered C function that reads one line at a time from a file descriptor, with a multi-descriptor bonus.

## In this repository

- Reads in chunks and preserves unread data between successive calls.
- Returns a dynamically allocated line, including the trailing newline when present.
- The bonus maintains independent read state for multiple descriptors.

## Build and run

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 -c get_next_line.c get_next_line_utils.c
```

Include `get_next_line.h`, link both source files, and free each returned line after use. For the bonus use the corresponding `_bonus` header and source files. The bonus tracks descriptors below `OPEN_MAX`, with a fallback limit of 1024 where the platform does not define it.

## Credits

Created as part of the 42 curriculum by akella.
