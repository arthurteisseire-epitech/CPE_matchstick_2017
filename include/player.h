/*
** EPITECH PROJECT, 2017
** File Name : player.h
** File description:
** by Arthur Teisseire
*/


#ifndef PLAYER_H
#define PLAYER_H

int player_io(map_t *map);
int input(map_t *map, int (*f)(map_t *map, char *input), char *ouput);
int stick_errors(map_t *map, char *input);
int line_errors(map_t *map, char *input);
void print_player_info(map_t *map);

#endif
