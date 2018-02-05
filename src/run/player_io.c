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
	remove_sticks(map, map->stick_in, map->line_in - 1);
	print_player_info(map);
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

void print_player_info(map_t *map)
{
	my_putstr("Player removed ");
	my_put_nbr(map->stick_in);
	my_putstr(" match(es) from line ");
	my_put_nbr(map->line_in);
	my_putchar('\n');
}
