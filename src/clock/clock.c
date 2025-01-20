/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** clock
*/

#include "my.h"
#include <stdio.h>

static float generate_random_y(float max_height)
{
    return (float)(rand() % (int)max_height);
}

static void respawn(app_t *app, int i)
{
    app->mob[i].life = 1;
    app->mob[i].position.x = 0;
    app->mob[i].position.y = generate_random_y(app->window->video_mode.height
        / 2 + 100);
    app->mob[i].speed = app->mob->speed;
    app->mob[i].vector.x = app->mob[i].speed;
    app->mob[i].vector.y = 0;
    app->mob[i].rect.width = 47.5;
    app->mob[i].rect.height = 57;
    app->mob[i].rect.top = 0;
    app->mob[i].rect.left = 0;
    sfSprite_setTexture(app->mob[i].sprite, app->mob[i].texture, sfTrue);
    sfSprite_setPosition(app->mob[i].sprite, app->mob[i].position);
    sfSprite_setTextureRect(app->mob[i].sprite, app->mob[i].rect);
}

static void animation_line(app_t *app, int i)
{
    if (app->mob[i].rect.left == 384) {
        app->mob[i].rect.left = 0;
        app->mob[i].rect.top += 76;
    }
    if (app->mob[i].rect.left == 288)
        app->mob[i].rect.left = 384;
    if (app->mob[i].rect.left == 192)
        app->mob[i].rect.left = 288;
    if (app->mob[i].rect.left == 96)
        app->mob[i].rect.left = 192;
    if (app->mob[i].rect.left == 0)
        app->mob[i].rect.left = 96;
}

static void animation_death(app_t *app, int i)
{
    if (app->mob[i].rect.top == 380 && app->mob[i].rect.left == 96) {
        respawn(app, i);
        return;
    }
    animation_line(app, i);
    sfSprite_setTextureRect(app->mob[i].sprite, app->mob[i].rect);
}

static void animation(app_t *app, int i)
{
    if (app->mob[i].rect.left == 0)
        app->mob[i].rect.left = 47.5;
    if (app->mob[i].rect.left > 137 &&
        app->mob[i].rect.left < 141)
        app->mob[i].rect.left = 0;
    if (app->mob[i].rect.left == 190)
        app->mob[i].rect.left = 139.5;
    if (app->mob[i].rect.left > 141 &&
        app->mob[i].rect.left < 144)
        app->mob[i].rect.left = 190;
    if (app->mob[i].rect.left == 95)
        app->mob[i].rect.left = 142.5;
    if (app->mob[i].rect.left > 46 &&
        app->mob[i].rect.left < 48)
        app->mob[i].rect.left = 95;
    sfSprite_setTextureRect(app->mob[i].sprite,
        app->mob[i].rect);
}

static void choic_anim_mob(app_t *app, float delta_time, int i)
{
    animation_times_t *anim_times = &app->mob[i].anim_times;

    if (app->mob[i].life == 0) {
        anim_times->animation_time_death += delta_time;
        if (anim_times->animation_time_death >= 0.1f) {
            animation_death(app, i);
            anim_times->animation_time_death = 0.0f;
        }
    } else {
        anim_times->animation_time += delta_time;
        if (anim_times->animation_time >= 0.3f) {
            animation(app, i);
            anim_times->animation_time = 0.0f;
        }
    }
}

static void move_sprite(app_t *app, float delta_time)
{
    for (int i = 0; i < app->game->nb_sprite; i++) {
        if (app->mob[i].life > 0) {
            app->mob[i].position.x += app->mob[i].speed;
            sfSprite_setPosition(app->mob[i].sprite, app->mob[i].position);
        }
    }
}

void set_clock(app_t *app)
{
    float delta_time;

    app->crea_clock->time = sfClock_getElapsedTime(app->crea_clock->clock);
    delta_time = app->crea_clock->time.microseconds / 1000000.0f;
    move_sprite(app, delta_time);
    for (int i = 0; i < app->game->nb_sprite; i++) {
        choic_anim_mob(app, delta_time, i);
    }
    sfClock_restart(app->crea_clock->clock);
}
