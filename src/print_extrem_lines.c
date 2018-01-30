/*
** EPITECH PROJECT, 2017
** File Name : print_extrem_lines.c
** File description:
** by Arthur Teisseire
*/

#include "matchstick.h"

int print_extrem_line(int nb_row)
{
	int nb_stars = nb_row * 2 + 1;
	char buffer[nb_stars + 1];

	buffer[nb_stars] = '\0';
	for (int i = 0; i < nb_stars; i++)
		buffer[i] = '*';
	my_putstr(buffer);
}

