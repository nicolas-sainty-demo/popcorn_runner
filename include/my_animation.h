/*
** EPITECH PROJECT, 2021
** popcorn
** File description:
** my_animation
*/

#ifndef MY_ANIMATION_H_
#define MY_ANIMATION_H_
#include "../include/my_struct.h"

void jump_animation(super_stuct_t *runner, sfRenderWindow *window);
void walk_animation(super_stuct_t *runner, sfRenderWindow *window);
void move(super_stuct_t *runner);
void fill_picture(int *coords, sfSprite **sprites);
void animation_manager(super_stuct_t *runner, sfRenderWindow *window);
#endif /* !MY_ANIMATION_H_ */