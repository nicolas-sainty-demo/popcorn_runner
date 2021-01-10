/*
** EPITECH PROJECT, 2021
** popcorn
** File description:
** sound
*/

#include "../include/my_struct.h"
#include "../include/my_collision.h"
#include "../include/my_manager.h"
#include "../include/my_set.h"
#include "../include/my_animation.h"
#include "../include/my_update.h"
#include "../include/my_text_manager.h"

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

void playsound(super_stuct_t *runner)
{
    sfMusic *hit = sfMusic_createFromFile("fonts/hit.wav");
    sfMusic_play(hit);
}

char *choicepicture_one(int **coords, int i)
{
    if (coords[1][i] = 0) {

    }
}

void set_positionsa(int *obs)
{
    obs[1] = rand()%(4 - 1);
    obs[0] = rand()%(6 - 1);
}