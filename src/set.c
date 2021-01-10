/*
** EPITECH PROJECT, 2021
** popcorn
** File description:
** set
*/
#include "../include/my_struct.h"
#include "../include/my_sound.h"
#include "../include/my_collision.h"
#include "../include/my_manager.h"
#include "../include/my_animation.h"
#include "../include/my_update.h"
#include "../include/my_text_manager.h"

void set_cha(super_stuct_t *runner)
{
    sfVector2f vector = {200, 475};
    sfVector2f vector_sizer = {0.15, 0.15};
    sfTexture *poele = sfTexture_createFromFile("fonts/poele.png", NULL);
    sfTexture *bouilloire = sfTexture_createFromFile("fonts/bou.png", NULL);

    runner->cha.life = 3;
    runner->cha.run = malloc(sizeof(sfTexture *) * 6);
    runner->cha.cha = sfSprite_create();
    runner->cha.run[0] = sfTexture_createFromFile("fonts/walk one.png", NULL);
    runner->cha.run[1] = sfTexture_createFromFile("fonts/walk two.png", NULL);
    runner->cha.run[2] = sfTexture_createFromFile("fonts/walk three.png", NULL);
    runner->cha.run[3] = sfTexture_createFromFile("fonts/vol un.png", NULL);
    runner->cha.run[4] = sfTexture_createFromFile("fonts/vol deux.png", NULL);
    runner->cha.run[5] = sfTexture_createFromFile("fonts/vol trois.png", NULL);
    sfSprite_setTexture(runner->obs.bouilloire , bouilloire, NULL);
    sfSprite_setTexture(runner->obs.poele, poele, NULL);
    sfSprite_setTexture(runner->cha.cha, runner->cha.run[0], NULL);
    sfSprite_setPosition(runner->cha.cha, vector);
    sfSprite_setScale(runner->cha.cha, vector_sizer);
}

void set_obs(super_stuct_t *runner)
{
    sfVector2f vector_set = {1000, 400};
    sfVector2f vector_seta = {1700, 560};
    sfVector2f size = {0.45, 0.45};

    sfSprite_setPosition(runner->obs.bouilloire, vector_set);
    sfSprite_setPosition(runner->obs.poele, vector_seta);
    sfSprite_setScale(runner->obs.bouilloire, size);
    sfSprite_setScale(runner->obs.poele, size);
}

void set_map(super_stuct_t *runner)
{
    int i = 0;
    int coord[2];

    sfVector2f vector_scale = {0.5, 0.5};

    runner->obs.sprites = malloc(sizeof(sfSprite **) * 12);
    while (i < 12) {
        sfVector2f vector_a = {i * 300, 0};
        sfVector2f vector_b = {i * 300, 600};
        runner->obs.sprites[i] = malloc(sizeof(sfSprite *) * 2);
        runner->obs.sprites[i][0] = sfSprite_create();
        runner->obs.sprites[i][1] = sfSprite_create();
        set_positionsa(coord);
        fill_picture(coord, runner->obs.sprites[i]);
        sfSprite_setPosition(runner->obs.sprites[i][1], vector_a);
        sfSprite_setPosition(runner->obs.sprites[i][0], vector_b);
        sfSprite_setScale(runner->obs.sprites[i][1], vector_scale);
        sfSprite_setScale(runner->obs.sprites[i][0], vector_scale);
        i++;
    }
}

char *set_way_one(int coord)
{
    char *way_one;
    if (coord == 1) {
        way_one = "fonts/four.png";
    } else {
        way_one = "fonts/tiroir.png";
    }
    return (way_one);
}

char *set_way_two(int coord)
{
    char *way_two;
    if (coord == 1) {
        way_two = "fonts/fond.png";
    } else if (coord == 2) {
        way_two = "fonts/fond.png";
    } else {
        way_two = "fonts/fond.png";
    }
    return (way_two);
}