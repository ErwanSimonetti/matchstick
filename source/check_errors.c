/*
** EPITECH PROJECT, 2021
** check_errors.c
** File description:
** returns 84 in case of error
*/

#include "matchstick.h"

int check_errors (int ac, char const * const av[])
{
    if (ac != 3) {
        print_error_msg("error: wrong number of arguments\n");
        return (84);
    }
    if (my_getnbr(av[1]) <= 1 || my_getnbr(av[1]) >= 100) {
        print_error_msg("error: number of lines must be between 1 and 100\n");
        return (84);
    }
    if (my_getnbr(av[2]) <= 0) {
        print_error_msg(
            "error: number of matches taker can't be negative or null\n");
        return (84);
    }
    return (0);
}
