#include "main.h"


/**
 * *my_str_copy - this function jobs is to copy a string
 * @source: this variable is the second string input type
 * @destination: this is a variable dstination
 * Return:t this should return the result of the comparison
 */
char *my_str_copy(char *destination, char *source)
{
	int t = 0;

	if (destination == source || source == 0)
		return (destination);
	while (source[t])
	{
		destination[t] = source[t];
		t++;
	}
	destination[t] = 0;
	return (destination);
}

/**
 * str_duplicate - this finctions job duplicates
 * the/a string input or output
 * @stringfield: this variable is the string input type
 * Return:should return the address to string duplicated
 */
char *str_duplicate(const char *stringfield)
{
	char *duplicatestr;
	int lengthstr = 0;

	if (stringfield == NULL)
		return (NULL);
	while (*stringfield++)
		lengthstr++;
	duplicatestr = malloc(sizeof(char) * (lengthstr + 1));
	if (!duplicatestr)
		return (NULL);
	for (lengthstr++; lengthstr--;)
		duplicatestr[lengthstr] = *--stringfield;
	return (duplicatestr);
}
