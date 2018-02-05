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
	print_map(map);
	while (1) {
		if (player_io(map) == -1)
			return (0);
		print_map(map);
		if (map->nb_sticks == 0) {
			my_putstr("You lost, too bad...\n");
			return (2);
		}
		ai_output(map);
		print_map(map);
		if (map->nb_sticks == 0) {
			my_putstr("I lost... snif... but "
			"I'll get you next time!!\n");
			return (1);
		}
	}
	return (0);
}

int remove_sticks(map_t *map, int nb_sticks, int index_line)
{
	int i = 0;

	while (i < nb_sticks) {
		map->line[index_line].last_stick[0] = ' ';
		map->line[index_line].last_stick -= 1;
		i++;
	}
	map->nb_sticks -= nb_sticks;
	map->line[index_line].nb_sticks -= nb_sticks;
	return (0);
}
