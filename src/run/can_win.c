/*
** EPITECH PROJECT, 2017
** File Name : can_win.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "matchstick.h"

int can_win(map_t *map, int *line, int *sticks)
{
	int nb_valid = count_valid_line(map);
	int f_valid = next_valid_line(map, 0);

	if (nb_valid == 1 && map->line[f_valid].nb_sticks <= map->max_sticks + 1) {
		*line = f_valid;
		if (map->line[f_valid].nb_sticks == map->max_sticks + 1)
			*sticks = map->max_sticks;
		else
			*sticks = map->line[f_valid].nb_sticks - 1;
		return (0);
	}
	if ((*line = all_empty_except_one(map)) != -1) {
		if (map->line[*line].nb_sticks == map->max_sticks + 1) {
			*line = first_one_stick_line(map);
			*sticks = 1;
			return (0);
		}
		if (map->line[*line].nb_sticks <= map->max_sticks) {
			set_nb_sticks(map, *line, sticks, nb_valid);
			return (0);
		}
	}
	return (-1);
}

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
