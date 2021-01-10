/*
** EPITECH PROJECT, 2021
** popcorn
** File description:
** displayer
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../include/my.h"
#include "../include/my_struct.h"
#include "../include/my_sound.h"
#include "../include/my_collision.h"
#include "../include/my_manager.h"
#include "../include/my_set.h"
#include "../include/my_animation.h"
#include "../include/my_update.h"
#include "../include/my_text_manager.h"

void obs_displayer(super_stuct_t *runner, sfRenderWindow *window)
{
    int i = (rand()%(500) + 2000);
    sfVector2f vector = {-1 - (runner->game.score)/2, 0};
    sfVector2f pos = sfSprite_getPosition(runner->obs.bouilloire);
    sfVector2f posa = sfSprite_getPosition(runner->obs.poele);
    sfVector2f vector_repeat = {i, 0};

    sfSprite_move(runner->obs.poele, vector);
    sfSprite_move(runner->obs.bouilloire, vector);
    if (pos.x < -250)
        sfSprite_move(runner->obs.bouilloire, vector_repeat);
    if (posa.x < -250)
        sfSprite_move(runner->obs.poele, vector_repeat);
    sfRenderWindow_drawSprite(window, runner->obs.bouilloire, NULL);
    sfRenderWindow_drawSprite(window, runner->obs.poele, NULL);
}

void wood_draw(super_stuct_t *runner, sfRenderWindow *window)
{
    sfVector2f vector = {1920, 6};
    sfVector2f pos = {0, 600};
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setSize(rect, vector);
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setFillColor(rect, sfColor_fromRGB(185, 185, 185));
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
}

void draw(super_stuct_t *runner, sfRenderWindow *window)
{
    int i = 0;

    update_map(runner);
    key_manager(runner);
    jump_manager(runner);
    while (i < 12) {
        sfRenderWindow_drawSprite(window, runner->obs.sprites[i][0], NULL);
        sfRenderWindow_drawSprite(window, runner->obs.sprites[i][1], NULL);
        i++;
    }
    animation_manager(runner, window);
    collision_manager(runner, window);
    texts_manager(runner, window);
    wood_draw(runner, window);
    sfRenderWindow_drawSprite(window, runner->cha.cha, NULL);
    game_over_manager(runner, window);
}

void windows_displayer(int height, int width, super_stuct_t *runner)
{
    sfVideoMode video_mode = {height, width, 32};
    sfRenderWindow *renderwindow = sfRenderWindow_create(video_mode, "W", sfDefaultStyle, NULL);
    runner->font = sfFont_createFromFile("fonts/bauhaus.ttf");
    runner->obs.bouilloire = sfSprite_create();
    runner->obs.poele = sfSprite_create();
    runner->cha.height = 0;
    runner->game.score = 0;
    runner->cha.time = 0;
    runner->game.time = 0;
    runner->cha.action = 0;
    set_map(runner);
    set_cha(runner);
    set_obs(runner);
    while (sfRenderWindow_isOpen(renderwindow)) {
        event_manager(renderwindow);
        draw(runner, renderwindow);
        sfRenderWindow_display(renderwindow);
    }
}