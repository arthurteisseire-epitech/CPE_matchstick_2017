/*
** EPITECH PROJECT, 2017
** File Name : main.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "matchstick.h"

int main(int ac, char **av)
{
	map_t map;

	if (ac != 3) {
		my_puterror("The program takes exactly 2 arguments\n");
		return (84);
	}
	/*
	 *if (check_args(&av[1]) == -1) {
	 *        my_puterror("Invalid arguments\n");
	 *        return (84);
	 *}
	 */
	map.nb_row = my_atoi(av[1]);
	map.max_sticks = my_atoi(av[2]);
	map.len_line = map.nb_row * 2 + 1;
	init_map(&map);
	print_extrem_line(map.nb_row);
	print_map(&map);
	print_extrem_line(map.nb_row);
	return (0);
}
