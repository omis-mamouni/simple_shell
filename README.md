# simple_shell
# Simple Shell Project

**A simple Unix command line interpreter**
![shell](/shell.png)

****
## Table of contents
 - **What is the shell?**
 - **About this project**
 - **Essential Functionalities of the Simple Shell**
 - **File description**
 - **List of allowed functions and system calls for this project**
 - **USAGE**
 - **Example of Usage**
 - **Bugs**
 - **TEAM**
 ******

## What is the shell?
The shell is a program that takes commands from the keyboard via the terminal, and gives them to the operating system to perform.\
**To better understand how the shell actually works, you can read our [Article].**

## About this project
This project is a simple version of the linux shell made for ALX taking part of the "Low-level programming & Algorithm - Linux and Unix system programming" projects.\
It is created using the **C programming Language** and it can do many functionalities that a real shell does.

## Essential Functionalities of the Simple Shell:
> Displays a prompt "#cisfun$ " and waits for user input.\
> Runs all commands of type "executable program" (ls and /bin/ls).\
> Runs the following build_in commands: **exit**, **env**, **setenv** and **unsetenv**.\
> Handles commands with arguments.\
> Handles the PATH global variable.\
> Handles The EOF (End Of File) condition.\
> Handles the Ctrl + C signal -> It doesn't exit the shell

## USAGE
You can try our shell by following these steps:
> **Step 1:** Clone our repository using this command, (you need to have git installed on your machine first)
````
git clone https://github.com/omis-mamouni/simple_shell
````
> **Step 2:** Change directory to simple_shell:
````
cd simple_shell
````
> **Step 3:** Compile the C files in this way:
````
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
````
> **Step 4:** Run the shell
````
./hsh
````
**Exiting the shell**
When you want to exit the shell, you can use one of the following methods:
> **1: Type the command "exit"**
````
exit
````
> **2: Press on Ctrl + D**
''
## Example of Usage
````
ubunto@ubuntu:~/Bureau/simple_shell$ gcc -Wall -Wextra -Werror -pedantic *.c -o hsh
ubunto@ubuntu:~/Bureau/simple_shell$ ./hsh
#cisfun$ echo Hello, This is an example
Hello, This is an example
#cisfun$ ls
README.md  checkbuild.c  line_exec.c  shell.c  string.c
buildin.c  hsh		 linkpath.c   shell.h
#cisfun$ ^C
#cisfun$ ls -l
total 52
-rw-r--r-- 1 ubunto ubunto  3067 Nov 26 04:22 README.md
-rw-r--r-- 1 ubunto ubunto  2183 Nov 24 16:17 buildin.c
-rw-r--r-- 1 ubunto ubunto   574 Nov 24 15:59 checkbuild.c
-rwxr-xr-x 1 ubunto ubunto 18144 Nov 26 04:22 hsh
-rw-r--r-- 1 ubunto ubunto  2091 Nov 24 14:49 line_exec.c
-rw-r--r-- 1 ubunto ubunto  1926 Nov 24 14:30 linkpath.c
-rw-r--r-- 1 ubunto ubunto   951 Nov 24 16:09 shell.c
-rw-r--r-- 1 ubunto ubunto  1351 Nov 24 15:58 shell.h
-rw-r--r-- 1 ubunto ubunto  1727 Nov 24 14:30 string.c
#cisfun$ exit
ubunto@ubuntu:~/Bureau/simple_shell$
````
## Bugs
No known Bugs.

