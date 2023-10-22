#include "shell.h"

/**
 *  _myhistory - it shows history list, single command per line, to be followed
 *  by line numbers, from 0.
 *  @info: its the structure contains potential arguments. it Use to maintain
 *  the constant function prototype.
 *  Return: it will always 0
 */

int _myhistory(info_t *info)

{
	print_list(info->history);
	return (0);
}

/**
 *  unset_alias - it will set alias to string char
 *  @info: the parameter structure
 *  @str: the string character alias
 *
 *  Return: 0 reps success, 1 indicate error
 */

int unset_alias(info_t *info, char *str)

{
	char *skd, cy;
	int reto;

	skd = _strchr(str, '=');
	if (!skd)
		return (1);
	cy = *skd;
	*skd = 0;
	reto = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*skd = cy;
	return (ret);
}

/**
 *  set_alias -it will set alias to charater string
 *  @info: it the parameter structure
 *  @str: string char alias
 *
 *  Return: 0 it reps success, 1  it reps error
 */

int set_alias(info_t *info, char *str)

{
	char *skd;

	skd = _strchr(str, '=');
	if (!skd)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));
	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - it prints out an alias string char
 * @node: reps the alias node
 *
 * Return: 0 reps success, 1 reps error
 */

int print_alias(list_t *node)

{
	char *skd = NULL, *cy = NULL;


	if (node)
	{
		skd = _strchr(node->str, '=');
		for (cy = node->str; cy <= skd; cy++)
		_putchar(*cy);
		_putchar('\'');
		_puts(skd + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 *  _myalias - mimics the alias builtin (man alias)
 *  @info: Structure containing potential arguments. Used to maintain
 *  constant function prototype.
 *  Return: Always 0
 */

int _myalias(info_t *info)

{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
