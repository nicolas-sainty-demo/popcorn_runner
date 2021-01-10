/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my
*/
#ifndef MY_STRUCT_H
#define MY_STRUCT_H
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
#include <SFML/Audio/Listener.h>
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/SoundBufferRecorder.h>
#include <SFML/Audio/SoundRecorder.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/SoundStream.h>

typedef struct game {
    int end;
    int score;
    int speed;
    int time;
    int jump_time;
    int start;
} game_t;

typedef struct obs {
    sfSprite ***sprites;
    sfSprite *bouilloire;
    sfSprite *poele;
    int count;
    int counta;
} obstacles_t;

typedef struct cha {
    sfSprite *cha;
    sfTexture **run;
    int life;
    int time;
    int action;
    int height;
    float speed;
} cha_t;

typedef struct super_struct {
    game_t game;
    sfFont *font;
    obstacles_t obs;
    cha_t cha;
} super_stuct_t;
#endif /* !MY_STRUCT_H_ */