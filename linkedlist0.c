#include "main.h"

/**
 * list_length - this function decides the length of the linked list
 * @prompt: this variable is pointer to the actual first node
 * Return: should return the size of the linked list
 */
size_t list_length(const list_s *prompt)
{
	size_t t = 0;

	while (prompt)
	{
		prompt = prompt->next;
		t++;
	}
	return (t);
}

/**
 * list_to_str - this function is the array of the strings is brought back
 * @i: this variable is the pointer to the head(beginning) node
 * Return: should always return an array of the strings
 */

char **list_to_str(list_s *i)
{
	list_s *clot = i;
	size_t o = list_length(i);
	size_t j;
	char **stringofarray;
	char *stringlisting;

	if (!i || !o)
		return (NULL);
	stringofarray = malloc(sizeof(char *) * (o + 1));
	if (!stringofarray)
		return (NULL);
	for (o = 0; clot; clot = clot->next, o++)
	{
		stringlisting = malloc(string_length(clot->str) + 1);
		if (!stringlisting)
		{
			for (j = 0; j < o; j++)
				free(stringofarray[j]);
			free(stringofarray);
			return (NULL);
		}

		stringlisting = my_str_copy(stringlisting, clot->str);
		stringofarray[o] = stringlisting;
	}
	stringofarray[o] = NULL;
	return (stringofarray);
}

