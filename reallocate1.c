#include "main.h"

/**
 * my_realloc - its my alterna 4 realloc dis func reallocates a block of d mem
 * @prompt:this is the pointer to the previous allocated block
 * @oldblocksize: this is the byte size of the previous block
 * @newbar: this is the byte size of the new block size
 * Return: should return the address to the previous memory block
 */
void *my_realloc(void *prompt, unsigned int oldblocksize, unsigned int newbar)
{
	char *n;

	if (!prompt)
		return (malloc(newbar));
	if (!newbar)
		return (free(prompt), NULL);
	if (newbar == oldblocksize)
		return (prompt);

	n = malloc(newbar);
	if (!n)
		return (NULL);

	if (oldblocksize < newbar)
	{
		oldblocksize = oldblocksize;
	}
	else
	{
		oldblocksize = newbar;
	}

	while (oldblocksize--)
		n[oldblocksize] = ((char *)prompt)[oldblocksize];
	free(prompt);
	return (n);
}
