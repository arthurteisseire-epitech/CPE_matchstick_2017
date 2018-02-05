/*
** EPITECH PROJECT, 2017
** File Name : ai.h
** File description:
** by Arthur Teisseire
*/

#ifndef AI_H
#define AI_H

typedef struct map map_t;

int ai_output(map_t *map);
int get_ai_line(map_t *map);
int get_ai_sticks(map_t *map, int line);
void print_ai_info(int sticks, int line);
int next_valid_line(map_t *map, int line);
int good_move(map_t *map, int line, int sticks);
int check_each_line(map_t *map, int sticks);
int set_line_and_sticks(map_t *map, int *line, int *sticks);
int can_win(map_t *map, int *line, int *sticks);
int all_empty_except_one(map_t *map);
int count_valid_line(map_t *map);
int set_nb_sticks(map_t *map, int line, int *sticks, int nb_valid);
int first_one_stick_line(map_t *map);
int set_for_last_line(map_t *map, int *line, int *sticks, int nb_valid);
int set_on_all_one_sticks(map_t *map, int *line, int *sticks, int nb_valid);

#endif
