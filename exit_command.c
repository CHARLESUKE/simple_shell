#include "main.h"

/**
 **string_char - s functions job is to look for a stamp in a string
 *@t: this variable is the string to check for type
 *@prompt: this variable is the pointer type
 *Return: should always return (s) a pointer to the store area t
 */
char *string_char(char *prompt, char t)
{
	do {
		if (*prompt == t)
			return (prompt);
	} while (*prompt++ != '\0');

	return (NULL);
}
