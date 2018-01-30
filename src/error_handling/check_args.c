/*
** EPITECH PROJECT, 2017
** File Name : check_args.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"

int check_args(char **args)
{
	if (my_str_isnum(args[0]) && my_str_isnum(args[1]))
		return (0);
	return (-1);
}
