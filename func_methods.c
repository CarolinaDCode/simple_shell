#include "simpleshell.h"
/**
 * _strcmp - a function that compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: an integer result of the comparison
 */
int _strcmp(char *s1, char *s2)
{
	int res = 0;

	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}

	if (s1 != s2)
		res = *s1 - *s2;

	return (res);
}

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previsouly allocated by malloc
 * @old_size: size of the allocated memory for ptr
 * @new_size: new size of the new memory block
 * Return: pointer to the newly allocated memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *ptr1;
	char *old_ptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (malloc(new_size));

	ptr1 = malloc(new_size);
	if (!ptr1)
		return (NULL);

	old_ptr = ptr;

	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			ptr1[i] = old_ptr[i];
	}

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			ptr1[i] = old_ptr[i];
	}

	free(old_ptr);
	return (ptr1);
}

/**
 * _strcat - a function that concatenates two strings
 * @dest: string to copy to
 * @src: string to copy
 * Return: a pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int count1 = 0, count2 = 0;
	int len_src = 0;

	while (dest[count1] != '\0')
	{
		count1++;
	}
	len_src = _strlen(src);
	dest = _realloc(dest, count1, len_src + count1 + 1);
	while (src[count2] != '\0')
	{
		dest[count1] = src[count2];
		count2++;
		count1++;
	}
	dest[count1] =  '\0';
	return (dest);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: strs
 * Return: newStr
 */
char *_strdup(char *str)
{
	char *newStr;
	int i, size = 0;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		size++;

	newStr = (char *)malloc(sizeof(char) * size + 1);

	if (newStr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		newStr[i] = str[i];

	newStr[i] = '\0';
	return (newStr);
}

/**
 * _strtok - function that divides a string with a delimiter
 * @line: string to divide
 * @delim: delimiter
 * Return: copystr
 */
char *_strtok(char *line,  char *delim)
{
	int j;
	static char *str;
	char *copystr;

	if (line != NULL)
		str = line;
	for (; *str != '\0'; str++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (*str == delim[j])
				break;
		}
		if (delim[j] == '\0')
			break;
	}
	copystr = str;
	if (*copystr == '\0')
		return (NULL);
	for (; *str != '\0'; str++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (*str == delim[j])
			{
				*str = '\0';
				str++;
				return (copystr);
			}
		}
	}
	return (copystr);
}
