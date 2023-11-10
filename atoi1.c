#include "main.h"


/**
 * alpha_is - examine for alphabetum
 * @e: the intake character
 * Return: returns (1) if true and (0) if false
 */

int alpha_is(int e)
{
	if ((e >= 'a' && e <= 'z') || (e >= 'A' && e <= 'Z'))
		return (1);
	else
		return (0);
}


/**
 * is_delimeter - checks if character is a delimeter
 * @e: character to examine
 * @f: the delimeter
 * Return: returns (1) if there is a delimeter, (0) if false
 */
int is_delimeter(char e, char *f)
{
	while (*f)
		if (*f++ == e)
			return (1);
	return (0);
}
