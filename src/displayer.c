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
#include <SFML/System/Vector2.h>
#include <SFML/System.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stddef.h>

super_stuct_t draw(super_stuct_t runner, sfRenderWindow *window)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("fonts/pepe.jpeg", NULL);
    sfSprite_setTexture(sprite, texture, 1);
    sfVector2f vectortest = {200, 200};
    sfVector2f vectortest1 = {10, 10};
    sfSprite_setPosition(sprite, vectortest);
    //sfSprite_setScale(sprite, vectortest1);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    return (runner);
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

void windows_displayer(int height, int width, super_stuct_t runner)
{
    sfVideoMode video_mode = {height, width, 32};
    sfRenderWindow *renderwindow = sfRenderWindow_create(video_mode, "SFMLISALIVE!", sfDefaultStyle ,NULL);

    while (sfRenderWindow_isOpen(renderwindow))
    {
        event_manager(renderwindow);
        draw(runner, renderwindow);
        sfRenderWindow_display(renderwindow);
    }
}

/* void windows_displayer(int height, int width, super_stuct_t runner)
{
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode){1024, 600, 32}, "My_runner", sfClose, NULL);
    sfEvent event;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        draw(runner, window);
        sfRenderWindow_display(window);
    }
} */