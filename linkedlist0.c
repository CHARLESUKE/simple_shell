#include "main.h"

/**
 * list_length - determines length of linked list
 * @ptr: pointer to first node
 * Return: returns the size of linked list
 */
size_t list_length(const list_s *ptr)
{
	size_t s = 0;

	while (ptr)
	{
		ptr = ptr->next;
		s++;
	}
	return (s);
}

/**
 * list_to_str - array of strings is returned
 * @h: pointer to head node
 * Return: returns an array of strings
 */

char **list_to_str(list_s *h)
{
	list_s *node = h;
	size_t l = list_length(h);
	size_t i;
	char **string;
	char *str;

	if (!h || !l)
		return (NULL);
	string = malloc(sizeof(char *) * (l + 1));
	if (!string)
		return (NULL);
	for (l = 0; node; node = node->next, l++)
	{
		str = malloc(string_length(node->str) + 1);
		if (!str)
		{
			for (i = 0; i < l; i++)
				free(string[i]);
			free(string);
			return (NULL);
		}

		str = my_str_copy(str, node->str);
		string[l] = str;
	}
	string[l] = NULL;
	return (string);
}

