/*
** EPITECH PROJECT, 2021
** line_empty.c
** File description:
** returns true and false if empty
*/

#include "matchstick.h"

int line_empty(char *sticks, int line)
{
    int line_len = get_line_len(sticks);
    int cursor = line_len * line + 1;

    while (sticks[cursor] != '\n') {
        if (sticks[cursor] == '|')
            return (0);
        cursor += 1;
    }
    return (1);
}