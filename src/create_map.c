/*
** EPITECH PROJECT, 2017
** File Name : create_map.c
** File description:
** by Arthur Teisseire
*/

#include "matchstick.h"

int init_map(map_t *map)
{
	int i = 0;

	map->line = malloc(sizeof(line_t) * map->nb_row);
	if (map->line == NULL)
		return (-1);
	while (i < map->nb_row) {
		map->line[i]->nb_sticks = 2 * i + 1;
		set_map_line(map, i);
		i++;
	}
	return (0);
}
