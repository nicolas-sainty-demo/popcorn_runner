/*
** EPITECH PROJECT, 2021
** popcorn
** File description:
** key_manager
*/

#include "../include/my_struct.h"

void key_manager(super_stuct_t *runner)
{
    sfVector2f vector_pos = sfSprite_getPosition(runner->cha.cha);

    if ((sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) && (vector_pos.y >= 475)) {
        runner->cha.action = 1;
    }
}