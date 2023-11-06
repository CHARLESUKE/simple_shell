#include "main.h"

/**
 * add_node - it adds a node at the beginning of the linked list
 * @i: pointer to the head node
 * @stringfield: the string field of the node
 * @non: node index that is used by history(record)
 * Return: should return the size of linked list
 */

list_s *add_node(list_s **i, const char *stringfield, int non)
{
	list_s *brandnewnode;

	if (!i)
		return (NULL);
	brandnewnode = malloc(sizeof(list_s));
	if (!brandnewnode)
		return (NULL);
	memory_set((void *)brandnewnode, 0, sizeof(list_s));
	brandnewnode->num = non;
	if (stringfield)
	{
		brandnewnode->str = str_duplicate(stringfield);
		if (!brandnewnode->str)
		{
			free(brandnewnode);
			return (NULL);
		}
	}
	brandnewnode->next = *i;
	*i = brandnewnode;
	return (brandnewnode);
}

/**
 * add_to_list - this adds a node to the list
 * @i: this is the pointer to the head node
 * @stringfield: this is the string field of node
 * @non: this is the node index used by history
 * Return: should returns the size of list
 */

list_s *add_to_list(list_s **i, const char *stringfield, int non)
{
	list_s *newnode, *clot;

	if (!i)
		return (NULL);

	clot = *i;
	newnode = malloc(sizeof(list_s));
	if (!newnode)
		return (NULL);
	memory_set((void *)newnode, 0, sizeof(list_s));
	newnode->num = non;
	if (stringfield)
	{
		newnode->str = str_duplicate(stringfield);
		if (!newnode->str)
		{
			free(newnode);
			return (NULL);
		}
	}
	if (clot)
	{
		while (clot->next)
			clot = clot->next;
		clot->next = newnode;
	}
	else
		*i = newnode;
	return (newnode);
}
