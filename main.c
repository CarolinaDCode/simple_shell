#include "simpleshell.h"

/**
 *
 *
 *
 *
 */
int main(int argc, char **argv, char **enviroment)
{
	input_v var = {NULL, NULL};
	size_t cant_buff = 0;
	ssize_t len = 0;

	(void)argc;
	(void)argv;
	(void)enviroment;

	write(1,"#cisfun$ ",9);

	while((len = getline(&(var.buffer), &cant_buff, stdin)) != -1)
	{
		if (len > 1)
		{
			var.buffer[len - 1] = '\0';
		}

		var.array_inputs = brokentoken(var.buffer, " ");

		if (check_for_comand(&var) == NULL)
		{
			write(1, "./shell: No such file or directory\n", 36);
		}
		free(var.array_inputs);
		write(1,"#cisfun$ ", 9);
	}
	write(1,"\n", 1);
	free(var.buffer);
	return (0);
}
