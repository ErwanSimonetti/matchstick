/*
** EPITECH PROJECT, 2021
** matchstick.c
** File description:
** main file
*/

#include "matchstick.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int get_size_buffer (int lines)
{
    int single_line_len = (lines - 1) * 2 + 5;
    int nb_lines = lines + 2;
    int size_buffer = single_line_len * nb_lines;

    return (size_buffer);
}

int matchstick (int lines, int max_removed)
{
    char *sticks = write_sticks(lines);

    my_putstr(sticks);
    return (launch_game (sticks, lines, max_removed));
}