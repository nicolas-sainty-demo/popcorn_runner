/*
** EPITECH PROJECT, 2021
** popcorn
** File description:
** collision
*/
#include "../include/my_struct.h"
#include "../include/my_sound.h"
#include "../include/my_manager.h"
#include "../include/my_set.h"
#include "../include/my_animation.h"
#include "../include/my_update.h"
#include "../include/my_text_manager.h"

void collision_poele(super_stuct_t *runner)
{
    sfVector2f cha_pos = sfSprite_getPosition(runner->cha.cha);
    sfVector2f poele_pos = sfSprite_getPosition(runner->obs.poele);
    int max_left = max(cha_pos.x, poele_pos.x);
    int min_right = min(cha_pos.x + 109, poele_pos.x + 198);
    int max_down = max(cha_pos.y, poele_pos.y);
    int min_top = min(cha_pos.y + 124, poele_pos.y + 37);

    if (max_left < min_right && max_down < min_top && runner->obs.counta == 0) {
        runner->obs.counta++;
        runner->cha.life--;
        playsound(runner);
    }
    if (runner->obs.counta > 0)
        runner->obs.counta++;
    if (runner->obs.counta > 700)
        runner->obs.counta = 0;
}

void collision_bouilloire(super_stuct_t *runner)
{
    sfVector2f cha_pos = sfSprite_getPosition(runner->cha.cha);
    sfVector2f bouilloire_pos = sfSprite_getPosition(runner->obs.bouilloire);
    int max_left = max(cha_pos.x, bouilloire_pos.x);
    int min_right = min(cha_pos.x + 109, bouilloire_pos.x + 198);
    int max_down = max(cha_pos.y, bouilloire_pos.y);
    int min_top = min(cha_pos.y + 124, bouilloire_pos.y + 198);

    if (max_left < min_right && max_down < min_top && runner->obs.count == 0) {
        runner->obs.count++;
        runner->cha.life--;
        playsound(runner);
    }
    if (runner->obs.count > 0)
        runner->obs.count++;
    if (runner->obs.count > 900)
        runner->obs.count = 0;
}