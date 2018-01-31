/*
** EPITECH PROJECT, 2017
** File Name : check_args.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"

int check_args(char **args)
{
	int arg0 = my_atoi(args[0]);
	int arg1 = my_atoi(args[1]);

	if (!my_str_isnum(args[0]) && !my_str_isnum(args[1]))
		return (-1);
	if (arg0 <= 1 || arg0 >= 100)
		return (-1);
	if (arg1 <= 0)
		return (-1);
	return (0);
}
