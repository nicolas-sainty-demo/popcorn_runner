/*
** EPITECH PROJECT, 2021
** popcorn
** File description:
** animation
*/
#include "../include/my_struct.h"
#include "../include/my_sound.h"
#include "../include/my_collision.h"
#include "../include/my_manager.h"
#include "../include/my_set.h"
#include "../include/my_update.h"
#include "../include/my_text_manager.h"

void animation_manager(super_stuct_t *runner, sfRenderWindow *window)
{
    runner->game.time++;
    walk_animation(runner, window);
    jump_animation(runner, window);
}

void fill_picture(int *coords, sfSprite **sprites)
{

    char *way_one = set_way_one(coords[0]);
    char *way_two = set_way_two(coords[1]);
    sfTexture *texture_a = sfTexture_createFromFile(way_one, NULL);
    sfTexture *texture_b = sfTexture_createFromFile(way_two, NULL);
    sfSprite_setTexture(sprites[0], texture_a, sfTrue);
    sfSprite_setTexture(sprites[1], texture_b, sfTrue);
}

void move(super_stuct_t *runner)
{
    int i = 0;
    sfVector2f vector = {-1 - (runner->game.score)/2, 0};

    while (i < 12) {
        sfSprite_move(runner->obs.sprites[i][0], vector);
        sfSprite_move(runner->obs.sprites[i][1], vector);
        i++;
    }
}

void walk_animation(super_stuct_t *runner, sfRenderWindow *window)
{
    int i = 0;
    if (runner->cha.action == 0) {
        if (runner->game.time > 150)
            runner->game.time = 0;
        if (runner->game.time < 50)
            i = 0;
        if (runner->game.time > 50 && runner->game.time < 100)
            i = 1;
        if (runner->game.time > 100 && runner->game.time < 150)
            i = 2;
        sfSprite_setTexture(runner->cha.cha, runner->cha.run[i], NULL);
    }
}

void jump_animation(super_stuct_t *runner, sfRenderWindow *window)
{
    int i = 0;

    if (runner->cha.action == 0)
        runner->game.jump_time = 0;
    if (runner->cha.action == 1) {
        runner->game.jump_time++;
        if (runner->game.jump_time< 25)
            i = 5;
        if (runner->game.jump_time > 25 && runner->game.jump_time < 100)
            i = 4;
        if (runner->game.jump_time > 100) {
            i = 3;
        }
        sfSprite_setTexture(runner->cha.cha, runner->cha.run[i], NULL);
    }
}
