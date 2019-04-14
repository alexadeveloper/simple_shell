#SIMPLE SHELL 

##Description

Is a command line interpreter, read it from a terminal or a file.

***

##Usage

1. Clone the repository:
```console
https://github.com/alexadeveloper/simple_shell.git
```

2. Enter at directory
```console
cd simple_shell/
```

3. Compile:
```console
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

4. Execute:
```console
./hsh
```

##Functions

The functions used are: 

|Name | Description | Return|
|:--: | :-- | :--|
|_strcpy | Copy a string| Destination Pointer|
|_strlen | Calculate size of a string | Size a string|
|str_concat | Concat two string | Pointer to a array|
|build_argv | Build argv to send myexec | Array to pointer with arguments|
|build_path | Find path to execute | Pointer with the value of full path|
|_getline | Delimited a string input | The length of input|
|_strtok | Extract tokens from a string | A pointer to the next token|
|_strspn | Find some char into a string | The number of characters in the initial segment|
|get_value_env | Find the value of enviroment variable | Pointer start on value of variable|
|myexec | Execute a command | It was succesful or not|
|sighandler | Handle the signals | No Return|
|_realloc | Reallocates a memory block | Pointer a new allocation|
|_realloc_pointer | Reallocates memory of a pointer | Pointer a new allocation|
|main | Entry point of shell |  0 if succes|

###Files

The functions are organized in files:

Name | Functions
:--: | :--
basics.c | _strcpy, _strlen, str_concat
builders.c | build_argv, build_path
general.c | _getline, _strtok, _strspn, get_value_env, myexec
helper.c | sighandler
holberton.h | libraries and prototypes
memory.c | _realloc, _realloc_pointer
shell.c | main

###Examples

```console
$jessiFer> ls
basics.c    general.c  holberton.h  memory.c   shell.c
builders.c  helper.c   hsh          README.md  test
```

###Autors

Ferney Medina & Alexandra Fonseca
