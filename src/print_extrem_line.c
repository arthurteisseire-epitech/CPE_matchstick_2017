/*
** EPITECH PROJECT, 2017
** File Name : print_extrem_lines.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "matchstick.h"

void print_extrem_line(int nb_row)
{
	int nb_stars = nb_row * 2 + 1;
	char buffer[nb_stars + 2];

	buffer[nb_stars] = '\n';
	buffer[nb_stars + 1] = '\0';
	for (int i = 0; i < nb_stars; i++)
		buffer[i] = '*';
	my_putstr(buffer);
}

