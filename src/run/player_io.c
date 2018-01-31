/*
** EPITECH PROJECT, 2017
** File Name : player_io.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "matchstick.h"
#include "get_next_line.h"

int player_io(map_t *map)
{
	int status;

	map->line_in = 0;
	map->stick_in = 0;
	my_putstr("\nYour turn:\n");
	while ((status = input(map, line_errors, "Line: ")) != 0 ||
	(status = input(map, stick_errors, "Matches: ")) != 0) {
		if (status == -2)
			return (-1);
	}
	return (0);
}

int input(map_t *map, int (*f)(map_t *map, char *input), char *output)
{
	char *input;

	my_putstr(output);
	input = get_next_line(0);
	if (input == NULL)
		return (-2);
	if (f(map, input) == -1) {
		free(input);
		return (-1);
	}
	free(input);
	return (0);
}

int stick_errors(map_t *map, char *input)
{
	map->stick_in = my_atoi(input);
	if (!my_str_isnum(input) || map->stick_in <= 0) {
		my_putstr("Error: invalid input (positive number expected)\n");
		return (-1);
	}
	if (map->stick_in > map->max_sticks) {
		my_putstr("Error: you cannot remove more than ");
		my_put_nbr(map->max_sticks);
		my_putstr(" matches per turn\n");
		return (-1);
	}
	if (map->stick_in > map->line[map->line_in - 1].nb_sticks) {
		my_puterror("Error: not enough matches on this line\n");
		return (-1);
	}
	return (0);
}

int line_errors(map_t *map, char *input)
{
	map->line_in = my_atoi(input);
	if (!my_str_isnum(input) || map->line_in <= 0) {
		my_putstr("Error: invalid input (positive number expected)\n");
		return (-1);
	}
	if (map->line_in > map->nb_row) {
		my_putstr("Error: this line is out of range\n");
		return (-1);
	}
	return (0);
}
