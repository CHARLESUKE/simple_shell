#include "main.h"

/**
 * **token - this functions job is to split a string
 * into words and also repeated along delimeter are ignored
 * @sf: this variable is the string input type
 * @delimta: this variable is the delimeter tye
 * Return: should always return the address to a
 * string array as follows
 */

char **token(char *sf, char *delimta)
{
	int b, c, j, k;
	int wordstotal = 0;
	char **t;

	if (sf == NULL || sf[0] == 0)
		return (NULL);
	if (!delimta)
		delimta = " ";
	for (b = 0; sf[b] != '\0'; b++)
		if (!is_delimeter(sf[b], delimta) && (is_delimeter(sf[b + 1], delimta)
					|| !sf[b + 1]))
			wordstotal++;

	if (wordstotal == 0)
		return (NULL);
	t = malloc((1 + wordstotal) * sizeof(char *));
	if (!t)
		return (NULL);
	for (b = 0, c = 0; c < wordstotal; c++)
	{
		while (is_delimeter(sf[b], delimta))
			b++;
		j = 0;
		while (!is_delimeter(sf[b + j], delimta) && sf[b + j])
			j++;
		t[c] = malloc((j + 1) * sizeof(char));
		if (!t[c])
		{
			for (j = 0; j < c; j++)
				free(t[j]);
			free(t);
			return (NULL);
		}
		for (k = 0; k < j; k++)
			t[c][k] = sf[b++];
		t[c][k] = 0;
	}
	t[c] = NULL;
	return (t);
}
