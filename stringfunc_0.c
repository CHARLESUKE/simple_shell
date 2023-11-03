#include "main.h"

/**
 * string_length - function to return the length of a string
 * @str: the string whose length would be checked
 * Return: the lenght of string input
 */
size_t string_length(char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * str_concat - concatenates two string input
 * @adr: the address of buffer destination
 * @ssrc: the sourse of the buffer
 * Return: returns the address to destination buffer
 */
char *str_concat(char *adr, char *ssrc)
{
	char *des = adr;

	while (*adr)
		adr++;
	while (*ssrc)
		*adr++ = *ssrc++;
	*adr = *ssrc;
	return (des);
}
