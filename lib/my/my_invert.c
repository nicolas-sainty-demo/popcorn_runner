/*
** EPITECH PROJECT, 2020
** B-CPE-110-BDX-1-1-pushswap-nicolas.sainty
** File description:
** my_invert
*/

int *my_invert(int position_one, int position_two, int *list)
{
    int buf;
    buf = list[position_one];
    list[position_one] = list[position_two];
    list[position_two] = buf;
    return (list);
}