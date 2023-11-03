#include "main.h"


/**
 * signalHandler - blocks ctrl-C from exiting and display
 * a new prompt
 * @sig_num: signal number
 * Return: returns nothing (void)
 */

void signalHandler(__attribute__((unused))int sig_num)
{
	append_S("\n");
	append_S("$ ");
	_putchar(BUF_FLUSH);
}
