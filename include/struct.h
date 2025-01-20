/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** struct
*/

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct game_s {
    int difficulty;
    int score;
    int life;
    int nb_sprite;
    int i;
} game_t;

typedef struct window_s {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    float coef_x;
    float coef_y;
    int menu;
} window_t;

typedef struct button_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
} button_t;

typedef struct animation_times_s {
    float animation_time;
    float animation_time_death;
} animation_times_t;

typedef struct mob_s {
    sfTexture *texture;
    sfTexture *texture_death;
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f scale;
    sfVector2f vector;
    sfIntRect rect;
    int speed;
    int life;
    animation_times_t anim_times;
} mob_t;

typedef struct cursor_s {
    sfTexture *texture_game;
    sfTexture *texture_menu;
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f scale;
    sfVector2f vector;
    sfIntRect rect;
} cursor_t;

typedef struct back_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f scale;
    sfVector2f vector;
    sfIntRect rect;
} back_t;

typedef struct text_s {
    sfText *text;
    sfFont *font;
} text_t;

typedef struct song_s {
    sfMusic *music;
    int volume;
} song_t;

typedef struct crea_clock_s {
    sfClock *clock;
    sfTime time;
} crea_clock_t;

typedef struct view_s {
    sfView *view;
    sfVector2f size;
    sfVector2f center;
} view_t;

typedef struct app_s {
    view_t *view;
    button_t *buttons;
    window_t *window;
    back_t *background;
    mob_t *mob;
    cursor_t *cursor;
    song_t *song;
    crea_clock_t *crea_clock;
    text_t *text;
    game_t *game;
} app_t;

#endif
