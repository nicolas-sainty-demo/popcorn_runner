/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** function that reverse a string
*/

char *my_revstr(char *str)
{

    int i = 0;
    int j = 0;
    char k;

    while ((str[j]) != '\0') {
        j++;
    }
    j = j - 1;
    while (j > i) {
        k = str[i];
        str[i] = str[j];
        str [j] = k;
        i++;
        j--;
    }
    return (str);
}
