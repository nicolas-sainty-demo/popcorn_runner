/*
** EPITECH PROJECT, 2021
** popcorn
** File description:
** manager
*/
#include "../include/my_struct.h"
#include "../include/my_sound.h"
#include "../include/my_collision.h"
#include "../include/my_set.h"
#include "../include/my_animation.h"
#include "../include/my_update.h"
#include "../include/my_text_manager.h"

void collision_manager(super_stuct_t *runner, sfRenderWindow *window)
{
    collision_poele(runner);
    collision_bouilloire(runner);
    obs_displayer(runner, window);
}

void event_manager(sfRenderWindow *renderwindow)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(renderwindow, &event))
    {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(renderwindow);
    }
}

void jump_manager(super_stuct_t *runner)
{
    sfVector2f vector = {0, runner->cha.speed};
    sfVector2f vector_pos = sfSprite_getPosition(runner->cha.cha);
    sfVector2f pos = {200, 475};

    if (runner->cha.action == 1) {
        sfSprite_move(runner->cha.cha, vector);
        if (470 <= vector_pos.y && vector_pos.y <= 475) {
            runner->cha.speed = -2;
        } else {
            runner->cha.speed = runner->cha.speed + 0.005;
        }
        if (runner->cha.speed >= 0)
            runner->cha.action = -1;
    }
    if (runner->cha.action == -1) {
        sfSprite_move(runner->cha.cha, vector);
        runner->cha.speed = runner->cha.speed + 0.005;
        if (vector_pos.y >= 475) {
            runner->cha.action = 0;
            sfSprite_setPosition(runner->cha.cha, pos);
        }
    }
}

void texts_manager(super_stuct_t *runner, sfRenderWindow *window)
{
    sfRectangleShape *rectangle_score = sfRectangleShape_create();
    sfVector2f vector = {1480, 10};
    sfVector2f vector_size = {425, 130};
    sfText *life_points = update_life(runner);
    sfText *time = update_time(runner);
    sfText *score = update_score(runner);

    sfRectangleShape_setPosition(rectangle_score, vector);
    sfRectangleShape_setSize(rectangle_score, vector_size);
    sfRectangleShape_setFillColor(rectangle_score, sfColor_fromRGB(39, 25, 22));
    sfRenderWindow_drawRectangleShape(window, rectangle_score, NULL);
    sfRenderWindow_drawText(window, life_points, NULL);
    sfRenderWindow_drawText(window, time, NULL);
    sfRenderWindow_drawText(window, score, NULL);
}

void game_over_manager(super_stuct_t *runner, sfRenderWindow *window)
{
    if (runner->cha.life <= 0) {
        sfRectangleShape *rectangle = sfRectangleShape_create();
        sfVector2f vector = {1920, 1080};
        sfVector2f scale = {2, 2};
        sfVector2f vector_size = {475, 350};
        sfText *game_over = sfText_create();
        char *text = "game over";

        sfRectangleShape_setSize(rectangle, vector);
        sfRectangleShape_setFillColor(rectangle, sfBlack);
        sfRenderWindow_drawRectangleShape(window, rectangle, NULL);
        sfText_setFont(game_over, runner->font);
        sfText_setString(game_over, text);
        sfText_setCharacterSize(game_over, 100);
        sfText_setPosition(game_over, vector_size);
        sfText_setColor(game_over, sfRed);
        sfText_setStyle(game_over, sfTextBold);
        sfText_setScale(game_over, scale);
        sfRenderWindow_drawText(window, game_over, NULL);
    }
}