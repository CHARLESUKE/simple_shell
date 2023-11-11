#include "main.h"


/**
 **string_copy - this functions job is to duplicate a string
 *@destination: this variables is the string destination type
 *@source: this variable is the string source type
 *@m: this variable is the stamp amount copied type
 *Return: should always return the linked string
 */
char *string_copy(char *destination, char *source, int m)
{
	int b, c;
	char *f = destination; /* Dest */

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
 **string_concat - this fuctions type is the link for two strings
 *@destination:this variable is the 1st string input type
 *@source: this variable is the 2nd string input
 *@m: this variable is the number of bytes going to be used
 *Return: should always return the linked string
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
