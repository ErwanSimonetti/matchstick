/*
** EPITECH PROJECT, 2021
** ai_turn.c
** File description:
** makes AI play
*/

#include <stdlib.h>
#include "matchstick.h"

static int get_line_rm(int lines)
{
    int current_line = random() % 100;

    while (current_line == 0)
        current_line = random() % 100;
    while (current_line > lines)
        current_line -= lines;
    return (current_line);
}

static int get_sticks_on_line(char *sticks, int line_removed)
{
    int line_len = get_line_len(sticks);
    int cursor = line_len * line_removed;
    int sticks_on_line = 0;

    while (sticks[cursor] != '\n') {
        if (sticks[cursor] == '|')
            sticks_on_line += 1;
        cursor += 1;
    }
    return (sticks_on_line);
}

int ai_turn(char *sticks, int lines, int max_removed)
{
    int line_removed = get_line_rm(lines);
    int sticks_on_line = get_sticks_on_line(sticks, line_removed);
    int sticks_removed = 0;

    if (game_lost(sticks)) {
        my_putstr("You lost, too bad...\n");
        return (2);
    }
    while (sticks_on_line == 0) {
        line_removed = get_line_rm(lines);
        sticks_on_line = get_sticks_on_line(sticks, line_removed);
    }
    while (sticks_removed == 0 || sticks_removed > max_removed) {
        sticks_removed = random() % sticks_on_line + 1;
    }
    my_putchar('\n');
    my_putstr("AI's turn...\n");
    print_pre_sentence(line_removed, sticks_removed, 0);
    sub_sticks(sticks, line_removed, sticks_removed);
    my_putstr(sticks);
    launch_game(sticks, lines, max_removed);
}