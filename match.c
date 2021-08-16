#include "simpleshell.h"
#include <string.h>

/**
 *
 *
 */
void (*check_for_comand(input_v *vars))(input_v *vars)
{
	unsigned int i;
	comand_v check[] = {
		{"/bin/ls", comd_handling},
		{"ls", comd_handling},
		{NULL, NULL}
	};

	for (i = 0; check[i].p !=NULL; i++)
	{
		if (_strcmp(vars->array_inputs[0], check[i].name) == 0)
		{
			break;
		}
	}
	if (check[i].p != NULL)
	{
		check[i].p(vars);
	}
	return (check[i].p);
}

void comd_handling(input_v *vars)
{
	int child_pid;
	int status = 0;

	child_pid = fork();

	if (child_pid == -1)
		exit(1);

	if (child_pid == 0)
	{
		execve(vars->array_inputs[0], vars->array_inputs, NULL);
		free(vars->array_inputs);
		exit(1);
	}

	wait(&status);
	/*write(1,"Child exit status = %d\n\n\n", status);*/
}

void file1(input_v *vars)
{
	char *str = "Holaaaaaa";
	char *new_str;
	int counter = 0;
	int z = 0;

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


void bin_ls(input_v *vars)
{
	if (execve(vars->array_inputs[0], vars->array_inputs, NULL) == -1)
	{
		perror("Error:");
	}
}
