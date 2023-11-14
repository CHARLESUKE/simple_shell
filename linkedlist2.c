#include "main.h"


/**
 * node_index - this functions job gets the whole index of a node
 * @i: this variable is the pointer to the node list(s)
 * @m: this variable is the pointer to node
 * Return: should always return the index of the node or -1
 */
ssize_t node_index(list_s *i, list_s *m)
{
	size_t t = 0;

	while (i)
	{
		if (i == m)
			return (t);
		i = i->next;
		t++;
	}
	return (-1);
}
