/*
** EPITECH PROJECT, 2017
** File Name : main.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "matchstick.h"
#include "error_handling.h"

int main(int ac, char **av)
{
	map_t map;
	int winner;

	if (ac != 3) {
		my_puterror("The program takes exactly 2 arguments\n");
		return (84);
	}
	if (check_args(&av[1]) == -1) {
		my_puterror("Invalid arguments\n");
		return (84);
	}
	init_map(&map, &av[1]);
	winner = run_game(&map);
	free_map(&map);
	return (winner);
}
