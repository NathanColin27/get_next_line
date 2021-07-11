# get_next_line
> Reading a line on a fd is way too tedious

The goal is to implement a function that will read from a file descriptor until it meets a new line character (`\n`).

As you call the function again will read the next line, and so on.

Return values :

`1`  Line read.

`0`  EOF reached.

`-1` Error occured.
