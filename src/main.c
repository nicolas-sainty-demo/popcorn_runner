/*
** EPITECH PROJECT, 2021
** popcorn
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../include/my.h"
#include "../include/my_struct.h"
#include "../include/my_displayer.h"

game_t set_game(int prevscore)
{
    game_t game;
    game.start = 1;
    game.score = prevscore;
    return (game);
}

int main(int argc, char *argv)
{
    int score = 0;

    obstacles_t obstacles;
    super_stuct_t runner;

    windows_displayer(1920, 1080, &runner);
    return (0);
}