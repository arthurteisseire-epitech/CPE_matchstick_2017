/*
** EPITECH PROJECT, 2017
** File Name : tools.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "matchstick.h"
#include "ai.h"

int first_one_stick_line(map_t *map)
{
	int line = 0;

	while ((line = next_valid_line(map, line)) != -1) {
		if (map->line[line].nb_sticks == 1)
			return (line);
		line++;
	}
	return (-1);
}

int set_nb_sticks(map_t *map, int line, int *sticks, int nb_valid)
{
	if (nb_valid % 2 == 0)
		*sticks = map->line[line].nb_sticks;
	else
		*sticks = map->line[line].nb_sticks - 1;
	return (0);
}

int all_empty_except_one(map_t *map)
{
	int sticky_line = -1;
	int line = 0;

	while ((line = next_valid_line(map, line)) != -1) {
		if (map->line[line].nb_sticks > 1) {
			if (sticky_line != -1)
				return (-1);
			sticky_line = line;
		}
		line++;
	}
	return (sticky_line);
}

int count_valid_line(map_t *map)
{
	int i = 0;
	int line = 0;

	while ((line = next_valid_line(map, line)) != -1) {
		line++;
		i++;
	}
	return (i);
}
