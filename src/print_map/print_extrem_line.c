/*
** EPITECH PROJECT, 2017
** File Name : print_extrem_lines.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "matchstick.h"

void print_extrem_line(int len_line)
{
	char buffer[len_line + 2];

	buffer[len_line] = '\n';
	buffer[len_line + 1] = '\0';
	for (int i = 0; i < len_line; i++)
		buffer[i] = '*';
	my_putstr(buffer);
}

