/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** set_back_menu
*/

#include "my.h"

void set_back_menu(app_t *app)
{
    sfVector2f scale = {0.5, 0.5};

    app->background[1].scale = scale;
    app->background[1].sprite = sfSprite_create();
    app->background[1].texture =
        sfTexture_createFromFile("assets/back/back_menu.png", NULL);
    sfSprite_setScale(app->background[1].sprite, app->background[1].scale);
    sfSprite_setTexture(app->background[1].sprite, app->background[1].texture,
        sfTrue);
}
