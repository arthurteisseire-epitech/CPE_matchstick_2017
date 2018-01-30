/*
** EPITECH PROJECT, 2017
** File Name : free_map.c
** File description:
** by Arthur Teisseire
*/

#include "matchstick.h"

void free_map(map_t *map)
{
	int i = 0;

	while (i < map->nb_row) {
		free(map->line[i].str);
		i++;
	}
	free(map->line);
}
