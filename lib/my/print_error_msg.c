/*
** EPITECH PROJECT, 2020
** print_error_msg
** File description:
** to display errors
*/

#include <unistd.h>

void put_error_char(char c)
{
    write(2, &c, 1);
}

void print_error_nbr(int nb)
{
    int rest;

    if (nb >= 0)
    {
        if (nb >= 10)
        {
            rest = (nb % 10);
            nb = (nb - rest) / 10;
            print_error_nbr(nb);
            put_error_char(rest + '0');
        }
        else
            put_error_char(48 + nb % 10);
    }
    if (nb < 0)
    {
        put_error_char('-');
        nb = nb * (-1);
        print_error_nbr(nb);
    }
}

void print_error_msg(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        put_error_char(str[i]);
        i += 1;
    }
}
