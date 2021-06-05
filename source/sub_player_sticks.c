/*
** EPITECH PROJECT, 2021
** sub_player_sticks.c
** File description:
** remove player sticks until game lost
*/

#include "matchstick.h"

int get_line_len(char *sticks)
{
    int len = 0;

    while (sticks[len] != '\n')
        len += 1;
    return (len + 1);
}

void sub_player_sticks(int line, int *matches, char *sticks, int max_removed)
{
    int line_len = get_line_len(sticks);
    int cursor = line_len * line;
    int sticks_on_line = 0;

    while (sticks[cursor] != '|')
        cursor += 1;
    while (sticks[cursor] == '|') {
        cursor += 1;
        sticks_on_line += 1;
    }
    if (sticks_on_line < matches[0]) {
        print_error_msg("Error: not enough matches on this line\n");
        get_matches_p(matches, max_removed);
    }
    cursor -= 1;
    sub_sticks(sticks, line, matches[0]);
}