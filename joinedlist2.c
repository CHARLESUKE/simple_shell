#include "main.h"


/**
 * free_list - frees the list
 * @h_ptr: pointer to address of head node
 * Return: returns nothing (void)
 */

void free_list(list_s **h_ptr)
{
	list_s *h, *next, *node;

	if (!h_ptr || !*h_ptr)
		return;
	h = *h_ptr;
	node = h;
	while (node)
	{
		next = node->next;
		free(node->str);
		free(node);
		node = next;
	}
	*h_ptr = NULL;
}
