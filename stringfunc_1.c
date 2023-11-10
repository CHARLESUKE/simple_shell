#include "main.h"



/**
 * my_str_comp - this function job is to compare two string input
 * @firststring: this variables is the first string input type
 * @secondstring: this variable is the second string input type
 * Return: should negative if string1 < string2, positive
 * if string1 > string2,
 * (0) if string1 and string2 are the same
 */
int my_str_comp(const char *firststring, const char *secondstring)
{
	while (*firststring && *secondstring)
	{
		if (*firststring != *secondstring)
			return (*firststring - *secondstring);
		firststring++;
		secondstring++;
	}
	if (*firststring == *secondstring)
		return (0);
	else if (*firststring < *secondstring)
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}


/**
 * _check - this function checks if substrfin starts with strsearch
 * @strsearch: this variable is the string input to search type
 * @substrfin: this variable is the substring to find type
 * Return: should return NULL or a pointer of the next character of strsearch
 */
char *_check(const char *strsearch, const char *substrfin)
{
	while (*substrfin)
		if (*substrfin++ != *strsearch++)
			return (NULL);
	return ((char *)strsearch);
}
