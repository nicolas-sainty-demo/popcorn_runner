/*
** EPITECH PROJECT, 2021
** popcorn
** File description:
** my_manager
*/

#ifndef MY_MANAGER_H_
#define MY_MANAGER_H_
#include "../include/my_struct.h"

void collision_manager(super_stuct_t *runner, sfRenderWindow *window);
void event_manager(sfRenderWindow *renderwindow);
void jump_manager(super_stuct_t *runner);
void texts_manager(super_stuct_t *runner, sfRenderWindow *window);
void game_over_manager(super_stuct_t *runner, sfRenderWindow *window);

#endif /* !MY_MANAGER_H_ */