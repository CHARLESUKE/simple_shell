#include "main.h"


/**
 * convert_num - this function is the modifier function,
 * a duplicate(clone)of itoa type
 *@numeral: this variable is the number type
 *@support: this variable is the framework type
 *@myflags: this bariable is the flags type
 * Return: should always return the transformed result (string)
 */

char *convert_num(long int numeral, int support, int myflags)
{
	static char *array;
	static char buffon[50];
	char signboard = 0;
	char *prompt;
	unsigned long m = numeral;

	if (!(myflags & CONVERT_UNSIGNED) && numeral < 0)
	{
		m = -numeral;
		signboard = '-';

	}
	array = myflags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	prompt = &buffon[49];
	*prompt = '\0';

	do	{
		*--prompt = array[m % support];
		m /= support;
	} while (m != 0);

	if (signboard)
		*--prompt = signboard;
	return (prompt);
}
