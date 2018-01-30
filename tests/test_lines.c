/*
** EPITECH PROJECT, 2017
** File Name : test_split.c
** File description:
** by Arthur Teisseire
*/

#include <criterion/criterion.h>
#include "my.h"
#include "matchstick.h"

Test(matchstick, atoi)
{
	cr_assert_eq(my_atoi("1"), 1);
	cr_assert_eq(my_atoi("3"), 3);
}
