/*
** EPITECH PROJECT, 2017
** File Name : ai.c
** File description:
** by Arthur Teisseire
*/

#include "matchstick.h"
#include "ai.h"

int set_line_and_sticks(map_t *map, int *line, int *sticks)
{
	*sticks = 1;
	while (*sticks <= map->max_sticks && *sticks <= map->len_line - 3) {
		if ((*line = check_each_line(map, *sticks)) != -1)
			return (0);
		(*sticks)++;
	}
	return (-1);
}

int check_each_line(map_t *map, int sticks)
{
	int line = 0;

	while (line < map->nb_row) {
		if (good_move(map, line, sticks) == 0)
			return (line);
		line++;
	}
	return (-1);
}

int good_move(map_t *map, int line, int sticks)
{
	int i = 0;
	int binary = 0;

	while (i < map->nb_row) {
		if (i == line && map->line[i].nb_sticks - sticks < 0)
			return (-1);
		if (i == line)
			binary ^= map->line[i].nb_sticks - sticks;
		else
			binary ^= map->line[i].nb_sticks;
		i++;
	}
	if (binary == 0)
		return (0);
	return (-1);
}

int next_valid_line(map_t *map, int line)
{
	while (line < map->nb_row) {
		if (map->line[line].nb_sticks > 0)
			return (line);
		line++;
	}
	return (-1);
}
