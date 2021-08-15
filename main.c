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

	write(1,"#cisfun$ ",10);

	while((len = getline(&(var.buffer), &cant_buff, stdin)) != -1)
	{
		if (len > 1)
			var.buffer[len - 1] = '\0';

		var.array_inputs = brokentoken(var.buffer, " ");

		if (check_for_comand(&var) == NULL)
			write(1, "./shell: No such file or directory\n", 37);

		write(1,"#cisfun$ ", 10);
	}

}
