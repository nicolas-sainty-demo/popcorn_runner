/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** something
*/

#include <unistd.h>

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    write(1, str, (i));
}