#include "simpleshell.h"
/**
 * main - function that evaluates whether the command exists
 * @ac: count
 * @av: array
 * @env: enviroment
 * Return: message
 */
int main(int ac, char **av, char **env)
{
	input_v var = {0, NULL, NULL, NULL, 0};
	size_t cant_buff = 0;
	ssize_t len = 0;

	(void)ac;
	var.name_pro = av[0];
	if (isatty(STDIN_FILENO))
		write(1, "#cisfun$ ", 9);
	while ((len = getline(&(var.buffer), &cant_buff, stdin)) != -1)
	{
		var.count++;
		if (len == 0)
			break;
		if (len > 1)
		{
			var.buffer[len - 1] = '\0';
			var.array_inputs = brokentoken(var.buffer, " ");
			var.exitstatus = check_for_comand(&var, env);
			if (var.exitstatus == 0)
			{
				var.exitstatus = comd_handling(&var, env);
				/*free(var.buffer);*/
				/*free(var.array_inputs);*/
			}
		}
		if (isatty(STDIN_FILENO))
			write(1, "#cisfun$ ", 9);
	}
	if (isatty(STDIN_FILENO))
		write(1, "\n", 1);
	if (var.count == 0)
		free(var.buffer);
	return (var.exitstatus);
}
