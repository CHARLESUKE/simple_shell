#include "main.h"

/**
 **string_char - looks for a stamp in a string
 *@t: string to check for
 *@prompt: pointer
 *Return: return (s) a pointer to the store area t
 */
char *string_char(char *prompt, char t)
{
	do {
		if (*prompt == t)
			return (prompt);
	} while (*prompt++ != '\0');

	return (NULL);
}

/**
 **string_copy - duplicate a string
 *@destination: string destination
 *@source: string source
 *@m: stamp amount copied
 *Return: returns the linked string
 */
char *string_copy(char *destination, char *source, int m)
{
	int b, c;
	char *f = destination; /* Destination */

	b = 0;
	while (source[b] != '\0' && b < m - 1)
	{
		destination[b] = source[b];
		b++;
	}
	if (b < m)
	{
		c = b;
		while (c < m)
		{
			destination[c] = '\0';
			c++;
		}
	}
	return (f);
}

/**
 **string_concat - link for two strings
 *@destination: 1st string input
 *@source: 2nd string input
 *@m: the number of bytes going to be used
 *Return: returns the linked string
 */

char *string_concat(char *destination, char *source, int m)
{
	int b, c;
	char *f = destination;

	b = 0;
	c = 0;
	while (destination[b] != '\0')
		b++;
	while (source[c] != '\0' && c < m)
	{
		destination[c] = source[c];
		b++;
		c++;
	}
	if (c < m)
		destination[b] = '\0';
	return (f);
}
