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

char *choicepicture_one(int **coords, int i)
{
    if(coords[1][i] = 0) {

    }
}

void set_positionsa(int *obstacles)
{
    obstacles[1] = rand()%(4 - 1);
    obstacles[0] = rand()%(6 - 1);
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

void fill_picture(int *coords, sfSprite **sprites)
{

    char *way_one = set_way_one(coords[0]);
    char *way_two = set_way_two(coords[1]);
    sfTexture *texture_a = sfTexture_createFromFile(way_one, NULL);
    sfTexture *texture_b = sfTexture_createFromFile(way_two, NULL);
    sfSprite_setTexture(sprites[0], texture_a, sfTrue);
    sfSprite_setTexture(sprites[1], texture_b, sfTrue);
}

void set_map(super_stuct_t *runner)
{
    int i = 0;
    int coord[2];

    sfVector2f vector_scale = {0.5, 0.5};

    runner->obstacles.sprites = malloc(sizeof(sfSprite **) * 12);
    while (i < 12) {
        sfVector2f vector_a = {i * 300, 0};
        sfVector2f vector_b = {i * 300, 600};
        runner->obstacles.sprites[i] = malloc(sizeof(sfSprite *) * 2);
        runner->obstacles.sprites[i][0] = sfSprite_create();
        runner->obstacles.sprites[i][1] = sfSprite_create();
        set_positionsa(coord);
        fill_picture(coord, runner->obstacles.sprites[i]);
        sfSprite_setPosition(runner->obstacles.sprites[i][1], vector_a);
        sfSprite_setPosition(runner->obstacles.sprites[i][0], vector_b);
        sfSprite_setScale(runner->obstacles.sprites[i][1], vector_scale);
        sfSprite_setScale(runner->obstacles.sprites[i][0], vector_scale);
        i++;
    }
}

void move(super_stuct_t *runner)
{
    int i = 0;
    sfVector2f vector = {-1 - (runner->game.score)/2, 0};

    while (i < 12) {
        sfSprite_move(runner->obstacles.sprites[i][0], vector);
        sfSprite_move(runner->obstacles.sprites[i][1], vector);
        i++;
    }
}

void update_map(super_stuct_t *runner)
{
    int coord[2];
    int i = 0;
    sfVector2f vector;
    sfVector2f vector_move = {3000, 0};

    move(runner);
    while (i < 12) {
        vector = sfSprite_getPosition(runner->obstacles.sprites[i][0]);
        if (vector.x < -300) {
            sfSprite_move(runner->obstacles.sprites[i][0], vector_move);
            sfSprite_move(runner->obstacles.sprites[i][1], vector_move);
        }
        i++;
    }
}

void key_manager(super_stuct_t *runner)
{
    sfVector2f vector_pos = sfSprite_getPosition(runner->character.character);

    if ((sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) && (vector_pos.y >= 475)) {
        runner->character.action = 1;
    }
}

void jump_manager(super_stuct_t *runner)
{
    sfVector2f vector = {0, runner->character.speed};
    sfVector2f vector_pos = sfSprite_getPosition(runner->character.character);
    sfVector2f pos = {200, 475};

    if (runner->character.action == 1) {
        sfSprite_move(runner->character.character, vector);
        if (470 <= vector_pos.y && vector_pos.y <= 475) {
            runner->character.speed = -2;
        } else {
            runner->character.speed = runner->character.speed + 0.005;
        }
        if (runner->character.speed >= 0)
            runner->character.action = -1;
    }
    if (runner->character.action == -1) {
        sfSprite_move(runner->character.character, vector);
        runner->character.speed = runner->character.speed + 0.005;
        if (vector_pos.y >= 475) {
            runner->character.action = 0;
            sfSprite_setPosition(runner->character.character, pos);
        }
    }
}

sfText *update_life(super_stuct_t *runner)
{
    char *text[2];
    text[0] = (runner->character.life + '0');
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

sfText *update_score(super_stuct_t *runner)
{
    sfText *score = sfText_create();
    sfVector2f vector = {1620, 15};
    sfVector2f scale = {2, 2};
    char *score_txt[2];

    score_txt[0] = (runner->game.score + '0');
    runner->character.time++;
    runner->game.speed++;
    if (runner->character.time > 10000) {
        runner->game.score++;
        runner->character.time = 0;
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
    if (runner->character.life <= 0) {
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

void walk_animation(super_stuct_t *runner, sfRenderWindow *window)
{
    int i = 0;
    if (runner->character.action == 0) {
        if (runner->game.time > 150)
            runner->game.time = 0;
        if (runner->game.time < 50)
            i = 0;
        if (runner->game.time > 50 && runner->game.time < 100)
            i = 1;
        if (runner->game.time > 100 && runner->game.time < 150)
            i = 2;
        sfSprite_setTexture(runner->character.character, runner->character.character_run[i], NULL);
    }
}

void jump_animation(super_stuct_t *runner, sfRenderWindow *window)
{
    int i = 0;

    if (runner->character.action == 0)
        runner->game.jump_time = 0;
    if (runner->character.action == 1) {
        runner->game.jump_time++;
        if (runner->game.jump_time< 25)
            i = 5;
        if (runner->game.jump_time > 25 && runner->game.jump_time < 100)
            i = 4;
        if (runner->game.jump_time > 100) {
            i = 3;
        }
        sfSprite_setTexture(runner->character.character, runner->character.character_run[i], NULL);
    }
}

void animation_manager(super_stuct_t *runner, sfRenderWindow *window)
{
    runner->game.time++;
    walk_animation(runner, window);
    jump_animation(runner, window);
}

void obstacles_displayer(super_stuct_t *runner, sfRenderWindow *window)
{
    int i = (rand()%(500) + 2000);
    sfVector2f vector = {-1 - (runner->game.score)/2, 0};
    sfVector2f pos = sfSprite_getPosition(runner->obstacles.bouilloire);
    sfVector2f posa = sfSprite_getPosition(runner->obstacles.poele);
    sfVector2f vector_repeat = {i, 0};

    sfSprite_move(runner->obstacles.poele, vector);
    sfSprite_move(runner->obstacles.bouilloire, vector);
    if (pos.x < -250)
        sfSprite_move(runner->obstacles.bouilloire, vector_repeat);
    if (posa.x < -250)
        sfSprite_move(runner->obstacles.poele, vector_repeat);
    sfRenderWindow_drawSprite(window, runner->obstacles.bouilloire, NULL);
    sfRenderWindow_drawSprite(window, runner->obstacles.poele, NULL);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

void playsound(super_stuct_t *runner)
{
    sfMusic *hit = sfMusic_createFromFile("fonts/hit.wav");
    sfMusic_play(hit);
}

void collision_poele(super_stuct_t *runner)
{
    sfVector2f character_pos = sfSprite_getPosition(runner->character.character);
    sfVector2f poele_pos = sfSprite_getPosition(runner->obstacles.poele);
    int max_left = max(character_pos.x, poele_pos.x);
    int min_right = min(character_pos.x + 109, poele_pos.x + 198);
    int max_down = max(character_pos.y, poele_pos.y);
    int min_top = min(character_pos.y + 124, poele_pos.y + 37);

    if (max_left < min_right && max_down < min_top && runner->obstacles.counta == 0) {
        runner->obstacles.counta++;
        runner->character.life--;
        playsound(runner);
    }
    if (runner->obstacles.counta > 0)
        runner->obstacles.counta++;
    if (runner->obstacles.counta > 700)
        runner->obstacles.counta = 0;
}

void collision_bouilloire(super_stuct_t *runner)
{
    sfVector2f character_pos = sfSprite_getPosition(runner->character.character);
    sfVector2f bouilloire_pos = sfSprite_getPosition(runner->obstacles.bouilloire);
    int max_left = max(character_pos.x, bouilloire_pos.x);
    int min_right = min(character_pos.x + 109, bouilloire_pos.x + 198);
    int max_down = max(character_pos.y, bouilloire_pos.y);
    int min_top = min(character_pos.y + 124, bouilloire_pos.y + 198);

    if (max_left < min_right && max_down < min_top && runner->obstacles.count == 0) {
        runner->obstacles.count++;
        runner->character.life--;
        playsound(runner);
    }
    if (runner->obstacles.count > 0)
        runner->obstacles.count++;
    if (runner->obstacles.count > 900)
        runner->obstacles.count = 0;
}

void collision_manager(super_stuct_t *runner, sfRenderWindow *window)
{
    collision_poele(runner);
    collision_bouilloire(runner);
    obstacles_displayer(runner, window);
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
        sfRenderWindow_drawSprite(window, runner->obstacles.sprites[i][0], NULL);
        sfRenderWindow_drawSprite(window, runner->obstacles.sprites[i][1], NULL);
        i++;
    }
    animation_manager(runner, window);
    collision_manager(runner, window);
    texts_manager(runner, window);
    wood_draw(runner, window);
    sfRenderWindow_drawSprite(window, runner->character.character, NULL);
    game_over_manager(runner, window);
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

void set_character(super_stuct_t *runner)
{
    sfVector2f vector = {200, 475};
    sfVector2f vector_sizer = {0.15, 0.15};
    sfTexture *poele = sfTexture_createFromFile("fonts/poele.png", NULL);
    sfTexture *bouilloire = sfTexture_createFromFile("fonts/bouilloire.png", NULL);

    runner->character.life = 3;
    runner->character.character_run = malloc(sizeof(sfTexture *) * 6);
    runner->character.character = sfSprite_create();
    runner->character.character_run[0] = sfTexture_createFromFile("fonts/marche un.png", NULL);
    runner->character.character_run[1] = sfTexture_createFromFile("fonts/marche deux.png", NULL);
    runner->character.character_run[2] = sfTexture_createFromFile("fonts/marche trois.png", NULL);
    runner->character.character_run[3] = sfTexture_createFromFile("fonts/vol un.png", NULL);
    runner->character.character_run[4] = sfTexture_createFromFile("fonts/vol deux.png", NULL);
    runner->character.character_run[5] = sfTexture_createFromFile("fonts/vol trois.png", NULL);
    sfSprite_setTexture(runner->obstacles.bouilloire , bouilloire, NULL);
    sfSprite_setTexture(runner->obstacles.poele, poele, NULL);
    sfSprite_setTexture(runner->character.character, runner->character.character_run[0], NULL);
    sfSprite_setPosition(runner->character.character, vector);
    sfSprite_setScale(runner->character.character, vector_sizer);
}

void set_obstacles(super_stuct_t *runner)
{
    sfVector2f vector_set = {1000, 400};
    sfVector2f vector_seta = {1700, 560};
    sfVector2f size = {0.45, 0.45};

    sfSprite_setPosition(runner->obstacles.bouilloire, vector_set);
    sfSprite_setPosition(runner->obstacles.poele, vector_seta);
    sfSprite_setScale(runner->obstacles.bouilloire, size);
    sfSprite_setScale(runner->obstacles.poele, size);
}

void windows_displayer(int height, int width, super_stuct_t *runner)
{
    sfVideoMode video_mode = {height, width, 32};
    sfRenderWindow *renderwindow = sfRenderWindow_create(video_mode, "SFMLISALIVE!", sfDefaultStyle ,NULL);
    runner->font = sfFont_createFromFile("fonts/bauhaus.ttf");
    runner->obstacles.bouilloire = sfSprite_create();
    runner->obstacles.poele = sfSprite_create();
    runner->character.height = 0;
    runner->game.score = 0;
    runner->character.time = 0;
    runner->game.time = 0;
    runner->character.action = 0;
    set_map(runner);
    set_character(runner);
    set_obstacles(runner);
    while (sfRenderWindow_isOpen(renderwindow)) {
        event_manager(renderwindow);
        draw(runner, renderwindow);
        sfRenderWindow_display(renderwindow);
    }
}