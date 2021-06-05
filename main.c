/*
** EPITECH PROJECT, 2020
** main
** File description:
** main function for push_swap
*/

#include "matchstick.h"

int main (int ac, char const * const av[])
{
    if (check_errors(ac, av) == 84)
        return (84);
    return (matchstick(my_getnbr(av[1]), my_getnbr(av[2])));
}
