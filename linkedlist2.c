#include "main.h"


/**
 * node_index - gets the index of a node
 * @h: pointer to node list
 * @n: pointer to the node
 * Return: returns the index of node or -1
 */
ssize_t node_index(list_s *h, list_s *n)
{
	size_t s = 0;

	while (h)
	{
		if (h == n)
			return (s);
		h = h->next;
		s++;
	}
	return (-1);
}
