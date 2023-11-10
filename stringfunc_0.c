#include "main.h"

/**
 * string_length - this functions job is to return length of a string
 * @stringfield: this variables job is the string whose length
 * should be checked
 * type
 * Return: should returnthe lenght of string input
 */
size_t string_length(char *stringfield)
{
	int lengthstr = 0;

	while (stringfield[lengthstr] != '\0')
	{
		lengthstr++;
	}
	return (lengthstr);
}

/**
 * str_concat - this functions job is to concatenates two string input
 * @bfj: this variable is the address of buffer destination type
 * @buffsource: this variable is the sourse of the buffer type
 * Return: should return the address to the destination buffer
 */
char *str_concat(char *bfj, char *buffsource)
{
	char *destination = bfj;

	while (*bfj)
		bfj++;
	while (*buffsource)
		*bfj++ = *buffsource++;
	*bfj = *buffsource;
	return (destination);
}
