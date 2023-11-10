#include "main.h"


/**
 * replace_str - this function job is to replace string
 * @p: this variable is the pointer to address of old string type
 * @m: this variable is the new string type
 * Return: should return (1) if it is replaced and (0) if not
 * replaced
 */

int replace_str(char **p, char *m)
{
	free(*p);
	*p = m;
	return (1);
}
