#include "shell.h"

/**
 * interactive - it will returns true if shell is interactive mode
 * @info: its a struct address
 * Return: 1 when its in an interactive mode, 0 if is absolutely not 
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
																		
/**
 * is_delim - it helps to check if character is a delimeter
 * @c: it is the character to be check
 * @delim: Reps (the delimeter string)
 * Return: 1 if it apears to be true, 0 if it is not
 */

int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - This will help check for alphabetic character
 * @c: Reps the character to input
 * Return: 1 it gives c if is an alphabetic, 0 if it is not 
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - it will convert  string to integer
 * @s: reps string to be converted
 * Return: 0 i.e is no number in string, it will otherwise convert number 
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
