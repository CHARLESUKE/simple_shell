#include "main.h"


/**
 * print_list_string - prints only the string element of the list
 * @ptr : pointer to the first node
 * Return: returns the size of linked list
 */

size_t print_list_string(const list_s *ptr)
{
	size_t s = 0;

	while (ptr)
	{
		append_S(ptr->str ? ptr->str : "(nil)");
		append_S("\n");
		ptr = ptr->next;
		s++;
	}
	return (s);
}

/**
 * delete_node - deletes node at an index
 * @h: address of pointer to first node
 * @i: index of node to delete
 * Return: returns (1) if deleted and (0) if not
 */

int delete_node(list_s **h, unsigned int i)
{
	list_s *prev, *node;
	unsigned int n = 0;

	if (!h || !*h)
		return (0);

	if (!i)
	{
		node = *h;
		*h = (*h)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *h;
	while (node)
	{
		if (n == i)
		{
			prev->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		n++;
		prev = node;
		node = node->next;
	}
	return (0);
}

