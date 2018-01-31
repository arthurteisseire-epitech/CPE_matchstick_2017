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
	while (1) {
		print_map(map);
		if (player_io(map) == -1)
			return (0);
		if (map->nb_sticks == 0) {
			my_putstr("You lost, too bad...\n");
			return (2);
		}
		print_map(map);
		ia_output(map);
		if (map->nb_sticks == 0) {
			my_putstr("I lost... snif... but I'll get you next time!!\n");
			return (1);
		}
	}
	return (0);
}

int remove_sticks(map_t *map, int nb_sticks, int index_line)
{
	int i = 0;

	while (i < nb_sticks) {
		map->line[index_line - 1].last_stick[0] = ' ';
		map->line[index_line - 1].last_stick -= 1;
		i++;
	}
	map->nb_sticks -= nb_sticks;
	map->line[index_line - 1].nb_sticks -= nb_sticks;
	return (0);
}
