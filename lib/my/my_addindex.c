/*
** EPITECH PROJECT, 2020
** B-PSU-100-BDX-1-1-myls-nicolas.sainty
** File description:
** my_addindex
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/my.h"

char *add_index(char *table)
{
    int j = 0;
    int i = my_strlen(table);
    char *new_table = malloc(sizeof(char) * i + 1);
    while (table[j] != '\0') {
        new_table[j] = table[j];
        j++;
    }
    return (new_table);
}