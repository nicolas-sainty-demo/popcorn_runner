/*
** EPITECH PROJECT, 2021
** popcorn
** File description:
** update
*/

#include "../include/my_struct.h"
#include "../include/my_sound.h"
#include "../include/my_collision.h"
#include "../include/my_manager.h"
#include "../include/my_set.h"
#include "../include/my_animation.h"
#include "../include/my_text_manager.h"

void update_map(super_stuct_t *runner)
{
    int coord[2];
    int i = 0;
    sfVector2f vector;
    sfVector2f vector_move = {3000, 0};

    move(runner);
    while (i < 12) {
        vector = sfSprite_getPosition(runner->obs.sprites[i][0]);
        if (vector.x < -300) {
            sfSprite_move(runner->obs.sprites[i][0], vector_move);
            sfSprite_move(runner->obs.sprites[i][1], vector_move);
        }
        i++;
    }
}

sfText *update_score(super_stuct_t *runner)
{
    sfText *score = sfText_create();
    sfVector2f vector = {1620, 15};
    sfVector2f scale = {2, 2};
    char *score_txt[2];

    score_txt[0] = (runner->game.score + '0');
    runner->cha.time++;
    runner->game.speed++;
    if (runner->cha.time > 10000) {
        runner->game.score++;
        runner->cha.time = 0;
    }
    sfText_setFont(score, runner->font);
    sfText_setString(score, score_txt);
    sfText_setCharacterSize(score, 50);
    sfText_setPosition(score, vector);
    sfText_setColor(score, sfRed);
    sfText_setStyle(score, sfTextBold);
    sfText_setScale(score, scale);
    return (score);
}

sfText *update_time(super_stuct_t *runner)
{
    sfText *score = sfText_create();
    sfVector2f vector = {1520, 70};
    sfVector2f scale = {2, 2};
    char *text = "level";

    sfText_setFont(score, runner->font);
    sfText_setString(score, text);
    sfText_setCharacterSize(score, 20);
    sfText_setPosition(score, vector);
    sfText_setColor(score, sfRed);
    sfText_setStyle(score, sfTextBold);
    sfText_setScale(score, scale);
    return (score);
}

sfText *update_life(super_stuct_t *runner)
{
    char *text[2];
    text[0] = (runner->cha.life + '0');
    sfVector2f vector = {1820, 15};
    sfVector2f scale = {2, 2};
    sfText *life_points = sfText_create();

    sfText_setFont(life_points, runner->font);
    sfText_setString(life_points, text);
    sfText_setCharacterSize(life_points, 50);
    sfText_setPosition(life_points, vector);
    sfText_setColor(life_points, sfRed);
    sfText_setStyle(life_points, sfTextBold);
    sfText_setScale(life_points, scale);
    return (life_points);
}