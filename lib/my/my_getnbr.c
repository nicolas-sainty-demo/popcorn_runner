/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_getnbr
*/

#include "../../include/my.h"

int	my_getnbr(char *str)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (str[0] == '-' && str[1] != '\0')
        i++;
    while (str[i] != '\0') {
        if ((str[i] < '0' || str[i] > '9'))
	        return (0);
        j = j + str[i] - 48;
        j = j * 10;
        i++;
    }
    j /= 10;
    if (str[0] == '-')
        return (-1 * j);
    else
        return (j);
}