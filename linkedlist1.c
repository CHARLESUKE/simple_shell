#include "main.h"


/**
 * prints_element - prints all elements of a linked list
 * @h: pointer to head node
 * Return: returns the size of list
 */

size_t prints_element(const list_s *h)
{
	size_t s = 0;

	while (h)
	{
		append_S(convert_num(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		append_S(h->str ? h->str : "(nil)");
		append_S("\n");
		h = h->next;
		s++;
	}
	return (s);
}

/**
 * start_node - identifies the string with prefix
 * @node: pointer to head node
 * @prefix: string to match
 * @c: the next character after prefix to match
 * Return: returns either a match or nothing
 */

list_s *start_node(list_s *node, char *prefix, char c)
{
	char *ptr = NULL;

	while (node)
	{
		ptr = _check(node->str, prefix);
		if (ptr && ((c == -1) || (*ptr == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}
