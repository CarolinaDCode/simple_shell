#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>

typedef struct var_input
{
	int count;
	char *buffer;
	char **array_inputs;
	char *name_pro;
} input_v;

typedef struct com_struct
{
	char *name;
	void (*p)(input_v *, char **);
} comand_v;

/*utility functions*/
void (*check_for_comand(input_v *vars, char **env))(input_v *vars, char **env);
char **brokentoken(char *buffer, char *delimiter);
int comd_handling(input_v *vars, char **env);
char *get_enviroment(char **env, char *comd);
char *get_dir_concat(char **new_env, char* comd);
void take_env(input_v *vars, char **env);


/*methods function C*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strtok(char *line, char *delim);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *convers_integer(int count);
size_t _getline(char **buff);

/*Command functions*/
void bin_ls(input_v *vars, char **env);
void exit_func(input_v *vars, char **env);

void file1(input_v *vars, char **env);
#endif
