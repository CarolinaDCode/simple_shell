#include "simpleshell.h"
/**
 *
 *
 *
 */
int _strlen(char *s)
{
	int iterador = 0;

	while (s[iterador] != '\0')
	{
		iterador++;
	}
	return (iterador);
}

/**
 *
 *
 *
 */
int _atoi(char *s)
{
	int sign = 1;

	unsigned int num = 0;

	do {
		if (*s == '-')
			sign = -1;
		else if (*s >= '0' && *s <= '9')
			num = (num * 10) + (*s - '0');
		else if (*s < '0' || *s > '9')
			return (-1);
		else if (num > 0)
			break;
	} while (*s++);

	return (num * sign);
}
/**
 *
 *
 *
 */
char *convers_integer(int count)
{
	char *num;
	int tmp, digits;

	tmp = count;

	for (digits = 0; tmp != 0; digits++)
		tmp /= 10;

	num = malloc(sizeof(char) * (digits + 1));
	if (num == NULL)
		return (NULL);

	num[digits--] = '\0';

	for (digits; count; digits--)
	{
		num[digits] = (count % 10) + '0';
		count /= 10;
	}
	return (num);
}
