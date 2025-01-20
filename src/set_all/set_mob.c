/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** set_duck
*/

#include "my.h"

static float generate_random_y(float max_height)
{
    return (float)(rand() % (int)max_height);
}

static void set_rect(app_t *app, int i)
{
    app->mob[i].rect.top = 0;
    app->mob[i].rect.left = 0;
    app->mob[i].rect.width = 47.5;
    app->mob[i].rect.height = 57;
}

static void set_mob_i(app_t *app, int i)
{
    sfVector2f scale = {1.25, 1.25};
    sfVector2f position =
        {0, generate_random_y(app->window->video_mode.height / 2 + 100)};

    app->mob[i].life = 1;
    app->mob[i].scale = scale;
    app->mob[i].position = position;
    app->mob[i].speed = app->mob->speed;
    app->mob[i].vector.x = app->mob[i].speed;
    app->mob[i].sprite = sfSprite_create();
    set_rect(app, i);
    app->mob[i].texture =
        sfTexture_createFromFile("assets/sprite/mob.png", NULL);
    app->mob[i].texture_death =
        sfTexture_createFromFile("assets/sprite/mob_death.png", NULL);
    sfSprite_setPosition(app->mob[i].sprite, app->mob[i].position);
    sfSprite_setScale(app->mob[i].sprite, app->mob[i].scale);
    sfSprite_setTexture(app->mob[i].sprite, app->mob[i].texture,
        sfTrue);
}

void set_mob(app_t *app)
{
    app->mob = malloc(sizeof(*(app->mob)) * 10);
    app->mob->speed = 1;
    for (int i = 0; i != 10; i++) {
        set_mob_i(app, i);
    }
}
