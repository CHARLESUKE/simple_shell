#include "main.h"


/**
 * free_list - this function job works to free the list
 * @highpointer: this variab jobs is the pointer to address of head node
 * Return: should always return nothing (void)
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
