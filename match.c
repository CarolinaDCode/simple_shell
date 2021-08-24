#include "simpleshell.h"
#include <string.h>

/**
 *
 *
 */
void (*check_for_comand(input_v *vars, char **env))(input_v *vars, char **env)
{
	unsigned int i;
	comand_v check[] = {
		{"exit", exit_func},
		{"env", file1},
		{"setenv", file1},
		{"unsetenv", file1},
		{"cd", file1},
		{"help", file1},
		{NULL, NULL}
	};
	(void)env;

	for (i = 0; check[i].p !=NULL; i++)
	{
		if (_strcmp(vars->array_inputs[0], check[i].name) == 0)
		{
			break;
		}
	}
	if (check[i].p != NULL)
	{
		check[i].p(vars, env);
	}
	return (check[i].p);
}

void exit_func(input_v *vars, char **env)
{
	int status = 0;
	int len;
	char *cont;
	(void)env;

	if (_strcmp(vars->array_inputs[0], "exit") == 0
	    && vars->array_inputs[1] != NULL)
	{
		status = _atoi(vars->array_inputs[1]);
		if(status == -1)
		{
			cont = convers_integer(vars->count);
			status = 2;
			write(1, cont, _strlen(cont));
			write(1, ": exit : Illegal number: ", 25);
			len = _strlen(vars->array_inputs[1]);
			write(1, vars->array_inputs[1], len);
			write(1, "\n", 1);
			free(cont);
			free(vars->array_inputs);
			free(vars->buffer);
			return;
		}
	}

	free(vars->array_inputs);
	free(vars->buffer);
	exit(status);
}

int comd_handling(input_v *vars, char **env)
{
	int child_pid, status = 0, in = 0;
	char *src_comd, *cont;

	if(access(vars->array_inputs[0], X_OK) == 0)
		src_comd = vars->array_inputs[0];
	else
	{
		src_comd = get_enviroment(env, vars->array_inputs[0]);
		in = 1;
		if (src_comd == NULL)
		{
			write(STDOUT_FILENO,
			      vars->name_pro,_strlen(vars->name_pro));
			write(STDOUT_FILENO, ": ", 2);
			cont = convers_integer(vars->count);
			write(STDOUT_FILENO, cont, _strlen(cont));
			write(STDOUT_FILENO, ": ", 2);
			write(STDOUT_FILENO, vars->array_inputs[0],
			      _strlen(vars->array_inputs[0]));
			write(STDOUT_FILENO, ": not found\n", 12);
			free(cont);
			free(src_comd);
			free(vars->array_inputs);
			return(127);
		}
	}
	child_pid = fork();
	if (child_pid == -1)
		exit(1);
	if (child_pid == 0)
	{
		execve(src_comd, vars->array_inputs, env);
		exit(1);
	}
	wait(&status);
	free(vars->buffer);
	free(vars->array_inputs);
	if (in == 1)
		free(src_comd);
}

void file1(input_v *vars, char **env)
{
	char *str = "Holaaaaaa";
	char *new_str;
	int counter = 0;
	int z = 0;
	(void)env;

	while (str[counter])
	{
		counter++;
	}

	new_str = malloc(sizeof(char) * counter + 1);

	while (z < counter)
	{
		new_str[z] = str[z];
		z++;
	}
	printf("%s\n", new_str);
	free(new_str);
}
