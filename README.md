# project 0x16. C - Simple Shell ✏️

### 🖋️ Description
***

The project is about creating our version of a command line interpreter: shell. Simple_shell is an sh-compatible command language interpreter that executes commands read from the standard input.

### 📋 Requirements
***
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
***
Your shell will be compiled this way:
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

### 🧪 Testing
***
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
***
| Files | Description |
| --- | --- |
| [simpleshell.h](https://github.com/CarolinaDCode/simple_shell/blob/master/simpleshell.h) | Header file. Contain all the prototype name of the functions. |
| [AUTHORS](https://github.com/CarolinaDCode/simple_shell/blob/master/AUTHORS) | Contains the authors of the project. |
| [man_1_simple_shell](https://github.com/CarolinaDCode/simple_shell/blob/master/man_1_simple_shell) | man page containing details about the usage of shell function.|
| [_getline.c](https://github.com/CarolinaDCode/simple_shell/blob/master/_getline.c) | Function that gets the commands by input from the terminal.|
| [brokentoken.c](https://github.com/CarolinaDCode/simple_shell/blob/master/brokentoken.c) | Item separating function.|
| [call_file_help.c](https://github.com/CarolinaDCode/simple_shell/blob/master/call_file_help.c) | Functions that call the help text files of each function.|
| [func_methods.c](https://github.com/CarolinaDCode/simple_shell/blob/master/func_methods.c) | Functions created to build the project.|
| [func_methods2.c](https://github.com/CarolinaDCode/simple_shell/blob/master/func_methods2.c) | Continuation of functions created to elaborate the project.|
| [get_enviroment.c](https://github.com/CarolinaDCode/simple_shell/blob/master/get_enviroment.c) | PATH manipulation function.|
| [main.c](https://github.com/CarolinaDCode/simple_shell/blob/master/main.c) | Function that evaluates whether the command exists.|
| [match.c](https://github.com/CarolinaDCode/simple_shell/blob/master/match.c) | Function that compares the command entered and the functions of each command.|
| [open_file.c](https://github.com/CarolinaDCode/simple_shell/blob/master/open_file.c) | function that compares the command entered, opens and reads the files of each help command.|
| [cd](https://github.com/CarolinaDCode/simple_shell/blob/master/cd) | Text file for reading the cd help.|
| [exit](https://github.com/CarolinaDCode/simple_shell/blob/master/exit) | Text file for reading the exit help.|
| [help](https://github.com/CarolinaDCode/simple_shell/blob/master/help) | Text file for reading the help help.|
| [help-help](https://github.com/CarolinaDCode/simple_shell/blob/master/help-help) | Text file for reading the help-help help.|
| [pwd](https://github.com/CarolinaDCode/simple_shell/blob/master/pwd) | Text file for reading the pwd help.|

### ✒️ Authors
***
*Holberton School Students*

Diana Carhuamanta - [CarolinaDCode](https://github.com/CarolinaDCode)

Geraldine Meneses - [nitaly31](https://github.com/nitaly31)
