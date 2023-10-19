#include "shell.h"

/**
 * interactive - it returns true when shell is interactive mode
 * @info: reps a struct address
 *
 * Return: 1 Reps interactive mode, 0 Reps non
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - it checks if character is a delimeter
 * @c: Showcase the char to check
 * @delim: Reps the delimeter string
 * Return: 1 Reps true, 0 Reps false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - it will check for alphabetic char
 * @c: our char to be inputed
 * Return: 1 rep c if it alphabetic, 0 when it is not
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - it will always convert string to integer
 * @s: a that string is converted																					
 * Return: 0 when no number string, convert number otherway 
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
