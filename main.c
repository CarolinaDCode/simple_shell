#include "simpleshell.h"

/**
 *
 *
 *
 *
 */
int main(int ac, char **av, char **env)
{
	input_v var = {0, NULL, NULL, NULL};
	ssize_t len = 0;

	(void)ac;
	var.name_pro = av[0];
	if (isatty(STDIN_FILENO))
		write(1,"#cisfun$ ",9);

	while(len != 0 || var.count == 0)
	{
		var.buffer = NULL;
		var.count++;
		len = _getline(&var.buffer);
		if (len == 0)
			break;
		if (len > 1)
		{
			var.buffer[len - 1] = '\0';
		}
		var.array_inputs = brokentoken(var.buffer, " ");
		if (check_for_comand(&var, env) == NULL)
		{
			if(!comd_handling(&var, env))
			{
				free(var.buffer);
				free(var.array_inputs);
			}
		}
		if (isatty(STDIN_FILENO))
			write(1,"#cisfun$ ", 9);
	}
	if (isatty(STDIN_FILENO))
		write(1,"\n", 1);
	free(var.buffer);
	return (0);
}
