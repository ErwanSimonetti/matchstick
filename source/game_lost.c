/*
** EPITECH PROJECT, 2021
** game_lost.c
** File description:
** returns true or false if there is no more sticks remaining
*/

#include "matchstick.h"

int game_lost(char *sticks)
{
    int count = 0;

    while (sticks[count] != '\0') {
        if (sticks[count] == '|')
            return (0);
        count += 1;
    }
    return (1);
}