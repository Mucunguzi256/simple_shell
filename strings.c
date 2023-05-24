#include "main.h"

/**
 * _strcmp - performs comparison of two strings.
 * @s1: str1
 * @s2: str2
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * custom_strcspn -  function calculates the length of the
 * initial segment of a string that consists of characters
 * @delim: para2
 * @str: para1
 * Return: count
*/
size_t custom_strcspn(const char* str, const char* delim) {
    size_t count = 0;

    while (*str) {
        if (findCharacter(delim, *str)) {
            break;
        }
        str++;
        count++;
    }
    return (count);
}

/**
 * findCharacter - search character
 * @str: para1
 * @c: para2
 * Return: NULL
*/
char* findCharacter(const char* str, char c)
{
    while (*str != '\0')
    {
        if (*str == c)
        {
            return (char*) str;
        }
        str++;
    }

    return (NULL);
}

/**
 *_puts - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}
