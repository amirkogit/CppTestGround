Running gdb 

- source must be compiled with -g option as follows:
$ g++ -g source.cpp

- At the command prompt type:
$ gdb a.out

- Once in the gdb prompt, type following commands
# to list program lines
(gdb) l

# to list next lines
(gdb) l

# to set a break point
(gdb) break 16

# to run till the break point
(gdb) r

# to print the content of i_vec
(gdb) p i_vec

# to print the content of i_vec in more human readable form
(gdb) pvector i_vec

# to step over next line
(gdb) n
(gdb) n
...

# to continue to rest of the program
(gdb) c

# to quit gdb
(gdb) q

...
