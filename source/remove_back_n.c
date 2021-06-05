/*
** EPITECH PROJECT, 2021
** remove_back_n.c
** File description:
** for getline
*/

#include "matchstick.h"

char *remove_back_n(char *str)
{
    int cursor = 0;

    while (str[cursor] != '\n' && str[cursor] != '\0')
        cursor += 1;
    if (str[cursor] == '\n')
        str[cursor] = '\0';
    return (str);
}