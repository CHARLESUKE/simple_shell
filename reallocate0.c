#include "main.h"

/**
 * memory_set - fills the memory set with byte
 * @p : pointer to memory
 * @b : bytes
 * @s : number of byes to be filled
 * Return: (p) the pointer to memory
 */

char *memory_set(char *p, char b, unsigned int s)
{
	unsigned int a;

	for (a = 0; a < s; a++)
		p[a] = b;
	return (p);
}

/**
* str_free - frees an array of strings
* @p: address to string
*/

void str_free(char **p)
{
	char **adr = p;

	if (!p)
		return;
	while (*p)
		free(*p++);
	free(adr);
}
