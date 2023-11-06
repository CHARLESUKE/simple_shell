#include "main.h"


/**
 * free_list - this function works to free the list
 * @highpointer: this variab job is the pointer to address of head node
 * Return: should returns nothing (void)
 */

void free_list(list_s **highpointer)
{
	list_s *i, *next, *clot;

	if (!highpointer || !*highpointer)
		return;
	i = *highpointer;
	clot = i;
	while (clot)
	{
		next = clot->next;
		free(clot->str);
		free(clot);
		clot = next;
	}
	*highpointer = NULL;
}
