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
	char *buffer;
	char **array_inputs;
} input_v;

typedef struct com_struct
{
	char *name;
	void (*p)(input_v *);
} comand_v;

/*utility functions*/
void (*check_for_comand(input_v *vars))(input_v *vars);
char **brokentoken(char *buffer, char *delimiter);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strcmp(char *s1, char *s2);
void comd_handling(input_v *vars);


/*Command functions*/
void bin_ls(input_v *vars);



void file1(input_v *vars);
#endif
