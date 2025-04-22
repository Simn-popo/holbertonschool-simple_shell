![image](https://github.com/user-attachments/assets/d5eb5318-61dc-4dad-9052-90286db1d541)

# Holberton School C - Simple Shell project


## Description

The Holberton School's Simple Shell project concludes the first term of the fundamentals program. This group project aims to test our knowledge of the bash shell and C language.

## Requirements
* Display a prompt and wait for the user to type a command. A command line always ends with a new line.
* The prompt is displayed again each time a command has been executed.
* The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
* The command lines are made only of one word. No arguments will be passed to programs.
* If an executable cannot be found, print an error message and display the prompt again.
* Handle errors.
* Have to handle the “end of file” condition (Ctrl+D)
* Handle command lines with arguments
* Handle the PATH
* fork must not be called if the command doesn’t exist
* Implement the exit built-in, that exits the shell
* Usage: exit
* Don’t have to handle any argument to the built-in exit
* Implement the env built-in, that prints the current environment

## Features
The main function implements an infinite loop to read commands entered by the user, parse them, and execute them. It supports commands with relative or absolute paths, checks for their existence, and displays an appropriate error message if a command does not exist.

📂Files main functions
|FILE|DESCRIPTION|
|:----------------|:----------------|
|main.c| Entry point and infinit loop|
|main.h| Contains the function prototypes and libraries|
|parse.c| Tokenizes the input string|
|execute.c| Creates child process and runs command|
|return_exe.c| Searches for an executable in the PATH|
|built_in.c| loops through and displays each environment variable|
|_getenv.c| Retrieves the value of an environment variable|

## Compilation
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
## Usages
* Interactive mode:
```
Hugo is the best SWE, I agree: ls
 AUTHORS                        README.md   a.out        execute.c   main.c   man_1_simple_shell   return_exe.c
'Flowcharts Simple Shell.pdf'   _getenv.c   built_in.c   hsh         main.h   parse.c
```
* Non-interactive mode:
```
echo "ls -l" | ./hsh
```
## Commands examples
```
/bin/ls
echo Hello world
pwd
env
```
## Testing
To test for memory leaks, we use "Valgrind" followed by the executable. The executable command for the example is: valgrind ls
```
Hugo is the best SWE, I agree: valgrind ls
==7462== Memcheck, a memory error detector
==7462== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==7462== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==7462== Command: ls
==7462==
 AUTHORS                        README.md   a.out        execute.c   main.c   man_1_simple_shell   return_exe.c
'Flowcharts Simple Shell.pdf'   _getenv.c   built_in.c   hsh         main.h   parse.c
==7462==
==7462== HEAP SUMMARY:
==7462==     in use at exit: 24,925 bytes in 20 blocks
==7462==   total heap usage: 254 allocs, 234 frees, 81,502 bytes allocated
==7462==
==7462== LEAK SUMMARY:
==7462==    definitely lost: 0 bytes in 0 blocks
==7462==    indirectly lost: 0 bytes in 0 blocks
==7462==      possibly lost: 0 bytes in 0 blocks
==7462==    still reachable: 24,925 bytes in 20 blocks
==7462==         suppressed: 0 bytes in 0 blocks
==7462== Rerun with --leak-check=full to see details of leaked memory
==7462==
==7462== For lists of detected and suppressed errors, rerun with: -s
==7462== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

## Flowchart
![image](https://github.com/user-attachments/assets/ca7cba31-ebaf-4803-ae29-5db6bc8c683a)
## Authors
* Laura Aupetit <laura.aupetit@holbertonstudents.com>
* Simon Paulin <simonpaulin@holbertonstudents.com>
* Christophe Barrere <christophe.barrere@holbertonstudents.com>
