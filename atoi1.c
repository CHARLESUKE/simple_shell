#include "main.h"


/**
 * alpha_is - this functions job is to examine for alphabetum
 * @e: this variables job is the intake character
 * Return: should return (1) if its true and (0) if its false
 */

int alpha_is(int e)
{
	if ((e >= 'a' && e <= 'z') || (e >= 'A' && e <= 'Z'))
		return (1);
	else
		return (0);
}


/**
 * is_delimeter - this functions job is to checks if character
 * is a delimeter
 * @e: this variables job is the character to examine type
 * @f: this variable is the delimeter type
 * Return: should return (1) if there is a delimeter, (0) if false
 */
int is_delimeter(char e, char *f)
{
	while (*f)
		if (*f++ == e)
			return (1);
	return (0);
}
