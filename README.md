# project 0x16. C - Simple Shell ✏️

### Description

The _printf() function takes one argument: a string of characters to print.
This string is made up of characters, each of which is printed exactly as it appears.
On the other hand, we have characters that normally print as expected, but when you add a specifier, they become special.
The format specifiers are:
FORMAT generates a specific format relative to the input of the specifier.

### Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* All your files will be compiled on Ubuntu 20.04 LTS using `gcc`, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the `Betty` style. It will be checked using betty-style.pl and betty-doc.pl
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to

### Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* All your files will be compiled on Ubuntu 20.04 LTS using `gcc`, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the `Betty` style. It will be checked using betty-style.pl and betty-doc.pl
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to

### ⚙ Compilation

Your shell will be compiled this way:
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

### Testing

Your shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

### 📂 files

| Files | Description |
| --- | --- |
| [simpleshell.h](https://github.com/CarolinaDCode/simple_shell/blob/master/simpleshell.h) | Header file. Contain all the prototype name of the functions. |
| [AUTHORS](https://github.com/CarolinaDCode/simple_shell/blob/master/AUTHORS) | Contains the authors of the project. |
| [man_1_simple_shell](https://github.com/CarolinaDCode/simple_shell/blob/master/man_1_simple_shell) | man page containing details about the usage of shell function.|


### ✒️ Authors

*Holberton School Student*
Diana Carhuamanta - [CarolinaDCode](https://github.com/CarolinaDCode)
Geraldine Meneses - [nitaly31](https://github.com/nitaly31)