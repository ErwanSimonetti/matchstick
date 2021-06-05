/*
** EPITECH PROJECT, 2021
** write_sticks.c
** File description:
** write all stics on a file
*/

#include "matchstick.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void fill_blanks(int lines, int *cursor, char *buffer)
{
    int current_cursor = 1;

    while (current_cursor != lines) {
        buffer[cursor[0]] = ' ';
        cursor[0] += 1;
        current_cursor += 1;
    }
}

void make_center(int lines, int *current_line, int *cursor, char *buffer)
{
    int count_bar = 0;
    int nb_bars = get_nb_sticks (current_line[0]);

    buffer[cursor[0]] = '*';
    cursor[0] += 1;
    fill_blanks(lines - current_line[0], cursor, buffer);
    while (count_bar != nb_bars) {
        buffer[cursor[0]] = '|';
        cursor[0] += 1;
        count_bar += 1;
    }
    fill_blanks(lines - current_line[0], cursor, buffer);
    buffer[cursor[0]] = '*';
    cursor[0] += 1;
    buffer[cursor[0]] = '\n';
    cursor[0] += 1;
    current_line[0] += 1;
}

void make_border(int lines, int *cursor, char *buffer)
{
    int current_cursor = 0;
    while (current_cursor != lines + lines + 1) {
        buffer[cursor[0]] = '*';
        current_cursor += 1;
        cursor[0] += 1;
    }
    buffer[cursor[0]] = '\n';
    cursor[0] += 1;
}

char *write_sticks(int lines)
{
    int cursor = 0;
    int current_line = 0;
    int size_buffer = get_size_buffer(lines);
    char *buffer = malloc(sizeof(char) * size_buffer);

    make_border(lines, &cursor, buffer);
    while (current_line != lines)
        make_center(lines, &current_line, &cursor, buffer);
    make_border(lines, &cursor, buffer);
    return (buffer);
}