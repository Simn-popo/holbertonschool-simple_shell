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

📂Files main functions
|FILE|DESCRIPTION|
|:----------------|:----------------|
|main.c| Entry point|
|main.h| Contains the function prototypes|
|parse.c||
|execute.c||
|return_exe.c||
|exit.c||
|built_in.c||
|_getenv.c||
## Compilation
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

## Flowchart
![image](https://github.com/user-attachments/assets/ca7cba31-ebaf-4803-ae29-5db6bc8c683a)
## Authors
* Laura Aupetit <laura.aupetit@holbertonstudents.com>
* Simon Paulin <simonpaulin@holbertonstudents.com>
* Christophe Barrere <christophe.barrere@holbertonstudents.com>
