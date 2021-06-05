/*
** EPITECH PROJECT, 2021
** sticks.c
** File description:
** contains function to use sticks
*/

#include "matchstick.h"

int get_nb_sticks (int current_line)
{
    int bars = 1;
    int line_bars = 0;

    if (current_line == 0)
        return (1);
    else {
        while (line_bars != current_line) {
            bars += 2;
            line_bars += 1;
        }
    return (bars);
    }
}