#include "main.h"


/**
 * *my_str_copy - copies a string
 * @str: first string input
 * @src: second string input
 * Return: returns the result of the comparison
 */
char *my_str_copy(char *dest, char *src)
{
	int s = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[s])
	{
		dest[s] = src[s];
		s++;
	}
	dest[s] = 0;
	return (dest);
}

/**
 * str_duplicate - duplicates a string input or output
 * @str: the string input
 * Return: returns the address to the string duplicated
 */
char *str_duplicate(const char *str)
{
	char *dup;
	int len = 0;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	for (len++; len--;)
		dup[len] = *--str;
	return (dup);
}
