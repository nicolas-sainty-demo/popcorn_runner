#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../include/my.h"
#include "../include/my_struct.h"
#include "../include/my_displayer.h"
#include <SFML/System/Vector2.h>
#include <SFML/System.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stddef.h>

game_t set_game(int prevscore)
{
    game_t game;
    game.start = 1;
    game.score = prevscore;
    return (game);
}

int **set_positions(int **obstacles)
{
    int i = 0;
    int prev = 0;
    while (i <= 5) {
        obstacles[0][i] = 0;
        obstacles[1][i] = 0;
        i++;
    }
    while (i <= 100) {
        int j = rand()%100;
        if (j < 10 && prev == 0) {
            obstacles[1][i] = 1;
            if (prev == 1 || prev == 2 || prev == 3) {
                obstacles[0][i] = 1;
            }
            prev = 1;
        } else if (j > 9 && j < 20) {
            obstacles[1][i] = 2;
            if (prev == 1 || prev == 2 || prev == 3) {
                obstacles[0][i] = 1;
            }
            prev = 2;
        } else if (j > 19 && j < 30) {
            obstacles[1][i] = 3;
            if (prev == 1 || prev == 2 || prev == 3) {
                obstacles[0][i] = 1;
            }
            prev = 3;
        } else {
            prev = 0;
        }
        i++;
    }
    return (obstacles);
}

int **generate_obstacles(int **obstacles)
{
    int i = 0;

    obstacles = malloc(sizeof(int*) * 2);
    obstacles[i] = malloc(sizeof(int) * 101);
    i++;
    obstacles[i] = malloc(sizeof(int) * 101);
    set_positions(obstacles);
/*     i = 0;
    while (i < 99) {
        printf("%d", obstacles[0][i]);
        i++;
    }
    i = 0;
    printf("\n");
    while (i < 99) {
        printf("%d", obstacles[1][i]);
        i++;
    } */
    return (obstacles);
}

obstacles_t set_obstacles(obstacles_t obstacles)
{
    obstacles.coords = generate_obstacles(obstacles.coords);
    return (obstacles);
}

int main(int argc, char *argv)
{
    int score = 0;

    obstacles_t obstacles;
    super_stuct_t runner;
    runner.game = set_game(score);
    runner.obstacles = set_obstacles(obstacles);
    windows_displayer(1000, 1000, runner);
    return (0);
}