/*
** EPITECH PROJECT, 2017
** File Name : can_win.c
** File description:
** by Arthur Teisseire
*/

#include "matchstick.h"
#include "ai.h"

int can_win(map_t *map, int *line, int *sticks)
{
	int nb_valid = count_valid_line(map);

	if (set_for_last_line(map, line, sticks, nb_valid) == 0)
		return (0);
	if (set_on_all_one_sticks(map, line, sticks, nb_valid) == 0)
		return (0);
	return (-1);
}

int set_on_all_one_sticks(map_t *map, int *line, int *sticks, int nb_valid)
{
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

int set_for_last_line(map_t *map, int *line, int *sticks, int nb_valid)
{
	int f_valid = next_valid_line(map, 0);

	if (nb_valid == 1 && 
	map->line[f_valid].nb_sticks <= map->max_sticks + 1) {
		*line = f_valid;
		if (map->line[*line].nb_sticks == 1)
			*sticks = 1;
		else if (map->line[f_valid].nb_sticks == map->max_sticks + 1)
			*sticks = map->max_sticks;
		else
			*sticks = map->line[f_valid].nb_sticks - 1;
		return (0);
	}
	return (-1);
}
