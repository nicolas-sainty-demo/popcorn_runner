/*
** EPITECH PROJECT, 2020
** B-PSU-100-BDX-1-1-myls-nicolas.sainty
** File description:
** my_sort_c
*/

int *sort_c(int *array, int size)
{
    int buf = 0;
    int v = 0;
    do {
        for (int i = 0; i < size; i++) {
            if (array[i] > array[i+1]) {
                buf = array[i];
                array[i] = array[i+1];
                array[i+1] = buf;
            }
        }
        v++;
    } while (v < size);
    return (array);
}