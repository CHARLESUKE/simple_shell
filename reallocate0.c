#include "main.h"

/**
 * memory_set -  this function fills the memory set with the byte(s)
 * @q :this variabale is the  pointer to memory
 * @c : this variable is the bytes
 * @t : this variable is the number of the byte(s) to be filled
 * Return: should return(q)the pointer to the memory
 */

char *memory_set(char *q, char c, unsigned int t)
{
	unsigned int b;

	for (b = 0; b < t; b++)
		q[b] = c;
	return (q);
}

/**
* str_free - this function work frees an array of the strings
* @q: this variable is the address to the string
*/

void str_free(char **q)
{
	char **bfj = q;

	if (!q)
		return;
	while (*q)
		free(*q++);
	free(bfj);
}
