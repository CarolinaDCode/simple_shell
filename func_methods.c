#include "simpleshell.h"
/**
 *
 *
 *
 */
int _strcmp(char *s1, char *s2)
{
        int it = 0;

        while (s1[it] != '\0' && s2[it] != '\0')
        {
                if (s1[it] != s2[it])
                {
                        return ((int) (s1[it] - s2[it]));
                }
                it++;
        }
        return (0);
}

/**
 *
 *
 *
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
 *
 *
 *
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
 *
 *
 *
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
 *
 *
 *
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
