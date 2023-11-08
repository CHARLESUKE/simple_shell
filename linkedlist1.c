#include "main.h"


/**
 * prints_element - this should print all available elements of a linked list
 * @i: this is a pointer to head(first) node
 * Return: it should return the size of lists
 */

size_t prints_element(const list_s *i)
{
	size_t t = 0;

	while (i)
	{
		append_S(convert_num(i->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		append_S(i->str ? i->str : "(nil)");
		append_S("\n");
		i = i->next;
		t++;
	}
	return (t);
}

/**
 * start_node - this should identifiey the string with the prefix
 * @clot: this is thee pointer to head(biginning) node
 * @theprefix: this is the string to match
 * @e: this is the next role after theprefix to match
 * Return: should returns either of a match or absolutely nothing
 */

list_s *start_node(list_s *clot, char *theprefix, char e)
{
	char *prompt = NULL;

	while (clot)
	{
		prompt = _check(clot->str, theprefix);
		if (prompt && ((e == -1) || (*prompt == e)))
			return (clot);
		clot = clot->next;
	}
	return (NULL);
}
