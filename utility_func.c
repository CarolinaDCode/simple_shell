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

    free(ptr);
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

    while (dest[count1] != '\0')
    {
        count1++;
    }

    while (src[count2] != '\0')
    {
        dest[count1] = src[count2];
        count2++;
        count1++;
    }

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

	newStr = (char *)malloc(size + 1 * sizeof(char));

	if (newStr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		newStr[i] = str[i];

	return (newStr);
}
