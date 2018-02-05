/*
** EPITECH PROJECT, 2017
** File Name : input_errors.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "matchstick.h"

int stick_errors(map_t *map, char *input)
{
	map->stick_in = my_atoi(input);
	if (!my_str_isnum(input)) {
		my_putstr("Error: invalid input (positive number expected)\n");
		return (-1);
	}
	if (map->stick_in == 0) {
		my_putstr("Error: you have to remove at least one match\n");
		return (-1);
	}
	if (map->stick_in > map->max_sticks) {
		my_putstr("Error: you cannot remove more than ");
		my_put_nbr(map->max_sticks);
		my_putstr(" matches per turn\n");
		return (-1);
	}
	if (map->stick_in > map->line[map->line_in - 1].nb_sticks) {
		my_putstr("Error: not enough matches on this line\n");
		return (-1);
	}
	return (0);
}

int line_errors(map_t *map, char *input)
{
	map->line_in = my_atoi(input);
	if (!my_str_isnum(input)) {
		my_putstr("Error: invalid input (positive number expected)\n");
		return (-1);
	}
	if (map->line_in > map->nb_row || map->line_in == 0) {
		my_putstr("Error: this line is out of range\n");
		return (-1);
	}
	return (0);
}
