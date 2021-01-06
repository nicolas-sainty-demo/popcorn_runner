/*
** EPITECH PROJECT, 2020
** B-CPE-110-BDX-1-1-pushswap-nicolas.sainty
** File description:
** my_putchar
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}