/*
** EPITECH PROJECT, 2017
** File Name : run_game.c
** File description:
** by Arthur Teisseire
*/

#include "matchstick.h"
#include "get_next_line.h"
#include "my.h"

int run_game(map_t *map)
{
	char *selected_line;
	char *removed_sticks;
	int index_line;
	int nb_sticks;

	while (map->nb_sticks > 0) {
		print_map(map);
		my_putstr("\nYour turn:\nLine: ");
		selected_line = get_next_line(0);
		//handle_line_errors(selected_line);
		my_putstr("Matches: ");
		removed_sticks = get_next_line(0);
		//handle_sticks_errors(removed_sticks);
		index_line = my_atoi(selected_line);
		nb_sticks = my_atoi(removed_sticks);
		remove_sticks(map, index_line - 1, nb_sticks);
		map->nb_sticks -= nb_sticks;
	}
	return (0);
}

int remove_sticks(map_t *map, int index_line, int nb_sticks)
{
	int i = 0;

	if (nb_sticks > map->line[index_line].nb_sticks)
		return (-1);
	while (i < nb_sticks) {
		map->line[index_line].last_stick[0] = ' ';
		map->line[index_line].last_stick -= 1;
		i++;
	}
	return (0);
}
