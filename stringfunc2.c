#include "main.h"


/**
 * replace_str - replaces string
 * @o: pointer to address of old string
 * @n: new string
 * Return: returns (1) if replaced and (0) if not
 */

int replace_str(char **o, char *n)
{
	free(*o);
	*o = n;
	return (1);
}
