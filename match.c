#include "simpleshell.h"
/**
 * check_for_comand - function that compares the command entered.
 * @vars: pointer that directs to the command array.
 * @env: enviroment
 * Return: command function
 */
void *check_for_comand(input_v *vars, char **env)
{
	unsigned int i;
	comand_v check[] = {
		{"exit", exit_func},
		{"env", take_env},
		{"setenv", file1},
		{"unsetenv", file1},
		{"cd", file1},
		{"help", file1},
		{NULL, NULL}
	};
	(void)env;

	for (i = 0; check[i].p != NULL; i++)
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
/**
 * exit_func - function that handles the exit arguments
 * @vars: pointer that directs to the command array.
 * @env: enviroment
 * Return: output, status or error
 */
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
		if (status == -1)
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
/**
 * comd_handling - evaluate and execute commands
 * @vars: pointer that directs to the command array
 * @env: enviroment
 * Return: src_comd
 */
int comd_handling(input_v *vars, char **env)
{	int child_pid, status = 0, in = 0;
	char *src_comd, *cont;

	if (access(vars->array_inputs[0], X_OK) == 0)
		src_comd = vars->array_inputs[0];
	else
	{
		src_comd = get_enviroment(env, vars->array_inputs[0]);
		in = 1;
		if (src_comd == NULL)
		{
			write(STDOUT_FILENO,
			      vars->name_pro, _strlen(vars->name_pro));
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
			return (127);
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
/**
 * take_env - function that gets global environment
 * @vars: pointer that directs to the command array
 * @env: enviroment
 * Return: env
 */
void take_env(input_v *vars, char **env)
{
	int n = 0;

	while (env[n])
	{
		write(STDOUT_FILENO, env[n], _strlen(env[n]));
		write(STDOUT_FILENO, "\n", 1);
		n++;
	}
}
/**
 * file1 - lalalala
 * @vars: vars
 * @env: env
 * Return: hola
 */
void file1(input_v *vars, char **env)
{
	printf("Hola");
}
