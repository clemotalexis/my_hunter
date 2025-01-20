/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** set_back_game
*/

#include "my.h"

void set_back_game(app_t *app)
{
    sfVector2f scale = {1, 1};

    app->background = malloc(sizeof(*(app->background)) * 2);
    app->background[0].scale = scale;
    app->background[0].sprite = sfSprite_create();
    app->background[0].texture =
        sfTexture_createFromFile("assets/back/back.png", NULL);
    sfSprite_setScale(app->background[0].sprite, app->background[0].scale);
    sfSprite_setTexture(app->background[0].sprite, app->background[0].texture,
        sfTrue);
}
