/*
** EPITECH PROJECT, 2021
** sub_sticks.c
** File description:
** sub sticks on specific line
*/

#include "matchstick.h"

void sub_sticks(char *sticks, int line, int matches)
{
    int line_len = get_line_len(sticks);
    int cursor = line_len * line;

    while (sticks[cursor] != '|')
        cursor += 1;
    while (sticks[cursor] == '|')
        cursor += 1;
    cursor -= 1;
    while (matches != 0) {
        sticks[cursor] = ' ';
        matches -= 1;
        cursor -= 1;
    }
}