#include "main.h"

/**
 * my_realloc - (my alternative for realloc) reallocates a block of memory
 * @ptr: pointer to previous allocated block
 * @old: byte size of previous block
 * @new: byte size of new block
 * Return: address to previous memory block
 */
void *my_realloc(void *ptr, unsigned int old, unsigned int new)
{
	char *m;

	if (!ptr)
		return (malloc(new));
	if (!new)
		return (free(ptr), NULL);
	if (new == old)
		return (ptr);

	m = malloc(new);
	if (!m)
		return (NULL);

	if (old < new)
	{
		old = old;
	}
	else
	{
		old = new;
	}

	while (old--)
		m[old] = ((char *)ptr)[old];
	free(ptr);
	return (m);
}
