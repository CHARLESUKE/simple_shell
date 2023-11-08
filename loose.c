#include "main.h"

/**
 * _free_ptr - this function basically frees the pointers address(home)
 * @prompt:thi is the pointer address(home)
 * Return: should return (0) if the action fails or else it returns (1)
 */
int _free_ptr(void **prompt)
{
	if (prompt && *prompt)
	{
		free(*prompt);
		*prompt = NULL;
		return (1);
	}
	return (0);
}
