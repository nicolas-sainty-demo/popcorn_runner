/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** find the size of a char *
*/

int my_strlen(char const *filepath)
{
    int i = 0;

    while (filepath[i] != '\0') {
        i++;
    }
    return (i);
}