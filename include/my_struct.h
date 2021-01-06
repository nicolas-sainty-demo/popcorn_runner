/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my
*/
#ifndef MY_STRUCT_H
#define MY_STRUCT_H
typedef struct game {
    int end;
    int score;
    int speed;
    int time;
    int start;
} game_t;

typedef struct obstables {
    int **coords;
} obstacles_t;

typedef struct character {
    int action;
    int height;
} character_t;

typedef struct super_struct {
    game_t game;
    obstacles_t obstacles;
    character_t character;
} super_stuct_t;
#endif /* !MY_STRUCT_H_ */