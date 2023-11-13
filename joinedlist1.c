#include "main.h"


/**
 * print_list_string - this function job is to emprints only
 * string element of the list
 * @prompt : this variab is a pointer to first node
 * Return: should always return size of linked list
 */

size_t print_list_string(const list_s *prompt)
{
	size_t t = 0;

	while (prompt)
	{
		append_S(prompt->str ? prompt->str : "(nil)");
		append_S("\n");
		prompt = prompt->next;
		t++;
	}
	return (t);
}

/**
 * delete_node - this function job is to delete node at an index
 * @i: this variab is the address of pointer to first node
 * @j: this variab is the index of node to delete
 * Return: should always return (1) if deleted and (0) if not deleted
 */

int delete_node(list_s **i, unsigned int j)
{
	list_s *previousclot, *clot;
	unsigned int m = 0;

	if (!i || !*i)
		return (0);

	if (!j)
	{
		clot = *i;
		*i = (*i)->next;
		free(clot->str);
		free(clot);
		return (1);
	}
	clot = *i;
	while (clot)
	{
		if (m == j)
		{
			previousclot->next = clot->next;
			free(clot->str);
			free(clot);
			return (1);
		}
		m++;
		previousclot = clot;
		clot = clot->next;
	}
	return (0);
}

