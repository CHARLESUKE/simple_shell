#include "main.h"

/**
 * add_node - adds a node to the start of the linked list
 * @h: pointer to head node
 * @str: string field of node
 * @no: node index used by history
 * Return: returns the size of linked list
 */

list_s *add_node(list_s **h, const char *str, int no)
{
	list_s *new_h;

	if (!h)
		return (NULL);
	new_h = malloc(sizeof(list_s));
	if (!new_h)
		return (NULL);
	memory_set((void *)new_h, 0, sizeof(list_s));
	new_h->num = no;
	if (str)
	{
		new_h->str = str_duplicate(str);
		if (!new_h->str)
		{
			free(new_h);
			return (NULL);
		}
	}
	new_h->next = *h;
	*h = new_h;
	return (new_h);
}

/**
 * add_to_list - adds a node to the list
 * @h: pointer to head node
 * @str: string field of node
 * @no: node index used by history
 * Return: returns the size of list
 */

list_s *add_to_list(list_s **h, const char *str, int no)
{
	list_s *new_nd, *node;

	if (!h)
		return (NULL);

	node = *h;
	new_nd = malloc(sizeof(list_s));
	if (!new_nd)
		return (NULL);
	memory_set((void *)new_nd, 0, sizeof(list_s));
	new_nd->num = no;
	if (str)
	{
		new_nd->str = str_duplicate(str);
		if (!new_nd->str)
		{
			free(new_nd);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_nd;
	}
	else
		*h = new_nd;
	return (new_nd);
}
