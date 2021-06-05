/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** functions relative to the game
*/

#include "matchstick.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void print_pre_sentence(int line, int matches, int player)
{
    if (player == 1)
        my_putstr("Player ");
    else
        my_putstr("AI ");
    my_putstr("removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

int is_num(char *string)
{
    int count = 0;

    while (string[count] != '\n') {
        if (string[count] < 48 || string[count] > 57)
            return (0);
        count += 1;
    }
    return (1);
}

int get_line_p(char *sticks, int *line, int lines)
{
    char *line_p = NULL;
    size_t size = 0;

    my_putstr("Line: ");
    if (getline(&line_p, &size, stdin) < 0)
        return (-1);
    if (is_num(line_p) == 0) {
        print_error_msg("Error: invalid input (positive number expected)\n");
        get_line_p (sticks, line, lines);
        return (0);
    } else if (line_p[0] == '0' || my_getnbr(line_p) > lines
    || line_empty(sticks, my_getnbr(line_p))) {
        print_error_msg("Error: this line is out of range\n");
        get_line_p (sticks, line, lines);
        return (0);
    } else {
        line[0] = my_getnbr(line_p);
        free(line_p);
        return (0);
    }
}

int get_matches_p(int *matches, int max_removed)
{
    char *matches_p = NULL;
    size_t size = 0;

    my_putstr("Matches: ");
    if (getline(&matches_p, &size, stdin) < 0)
        return (-1);
    if (matches_p[0] == '0') {
        print_error_msg("Error: you have to remove at least one match\n");
        get_matches_p (matches, max_removed);
        return (0);
    }
    else if (my_getnbr(matches_p) > max_removed) {
        print_error_msg("Error: you cannot remove more than ");
        print_error_nbr(max_removed);
        print_error_msg(" matches per turn\n");
        get_matches_p (matches, max_removed);
        return (0);
    } else {
        matches[0] = my_getnbr(matches_p);
        return (0);
    }
}

int launch_game(char *sticks, int lines, int max_removed)
{
    int line = 0;
    int matches = 0;

    if (game_lost(sticks)) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
    my_putchar('\n');
    my_putstr("Your turn:\n");
    if (get_line_p(sticks, &line, lines) == -1)
        return (0);
    if (get_matches_p(&matches, max_removed) == -1)
        return (0);
    if (matches != 0) {
        sub_player_sticks(line, &matches, sticks, max_removed);
        print_pre_sentence (line, matches, 1);
        my_putstr(sticks);
        return (ai_turn(sticks, lines, max_removed));
    };
    return (0);
}