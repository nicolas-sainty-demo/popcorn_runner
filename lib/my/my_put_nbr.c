/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** task07
*/

int thing(int a, int b)
{
    int c = a;

    if (b == 0) {
        a = 1;
    }
    while (b > 1) {
        a = a * c;
        b = b - 1;
    }
    return (a);
}

int antineg(int number)
{
    if (number < 0)
    {
        number = number * -1;
        my_putchar('-');
    }
    return (number);
}

int my_put_nbr(int nb)
{
    int a = 0;
    int b = 0;
    int firstnb = nb;
    int modnb = nb % 10;

    nb = antineg(nb);
    if (nb < 10) {
        int modnb = nb;
        my_putchar(modnb + 48);
        return (0);
    } else while (firstnb > 9) {
        a++;
        firstnb = firstnb / 10;
    } while (a > 0) {
        b = nb / thing(10, (a));
        nb = nb - (b * thing(10, (a)));
        my_putchar(b + 48);
        a--;
    }
    my_putchar(modnb + 48);
}