#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>



extern char **environ;

/**
 * struct Node_Struct - Struct environment variable
 * @name: the environment name
 * @value: the envirornment value
 * @next: a pointer to the next node
 */

typedef struct Node_Struct
{
	char *name;
	char *value;
	struct Node_Struct *next;
} env_Node;

/**
 * struct buildin_struct - Struct build-in commands
 * @cmd: The build in command
 * @func: the function associated
 */

typedef struct buildin_struct
{
	char *cmd;
	int (*func)(char *exe, int ac, char **av, char **e, int s, int l);
} buildin_commands;


int _strlen(char *str);
int character_is_delimiter(char c, const char *delim);
int Count_number_of_token(char *str, const char *delim);
char **_strtoken(char *str, const char *delim);
char *_strDuplicated(char *str);
char *_strCharacter(char *str, char c);
char *_strncat(char *dest, char *src, size_t n);
char *_memocpy(char *dest, char *src, size_t n);
void *_reallocMemo(void *ptr, size_t old_size, size_t new_size);
int reallocate_memory(char **lineptr, ssize_t n);
char *_strcpy(char *dest, char *src);
char *_strcat(char *str1, char *str2);
int _strcmp(char *str1, const char *str2);
void freeLists(char **ptr, int i);
int arrayLength(char **args);
int _string_to_integer(char *s);
int _checkDigit(int c);
void SIGINT_is_sent(int signal);
char **splits_input(char *lineptr, char **e, int s);
void printPromptString(void);
void free_array(char **av);
int execute_cmd(char *exe, char **av, char **e, int *flag, int *lvl);
void print_error_message(char *exe, char *desc);
void build_command_Path(char *dirPath, char *cmd, char *path);
char *_locateWhich(char *cmd, char *envPath);
char *_get_environment_variable(const char *name, char **e);
int print_command_notFound_error(char *exe, char **av, int l);
void exe_exit_cmd(int status, char **av, char *line, char **cmd);
void ignore_cmnt(char *lineptr);
void free_envNode_element(env_Node *node);
int replaceVar(char **args, char **e, int s);
char **parse_line_command(char *lineptr);
char *convertInteger(int n, int base, int upper_o_n);

/* Buildin functions */
int env_rm(char *exe, int ac, char **as, char **e, int s, int l);
int exit_ee(char *exe, int ac, char **as, char **e, int s, int l);
int (*GetBuild_f(char *c))(char *x, int a, char **v, char **e, int s, int l);



#endif

