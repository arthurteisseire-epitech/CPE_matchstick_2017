/*
** EPITECH PROJECT, 2017
** File Name : print_map.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "matchstick.h"

void print_map(map_t *map)
{
	int i = 0;

	while (i < map->nb_row) {
		my_putstr(map->line[i].str);
		my_putchar('\n');
		i++;
	}
}
