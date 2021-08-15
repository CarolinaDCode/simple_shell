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
		{"1", file1},
		{"2", file2},
		{NULL, NULL}
	};

	for (i = 0; check[i].p !=NULL; i++)
	{
		if (strcmp(vars->array_inputs[0], check[i].name) == 0)
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
	printf("cuándo se acabaran los task...");
}

void file2(input_v *vars)
{

}
