/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** set_cursor
*/

#include "my.h"

void set_cursor(app_t *app)
{
    sfVector2f scale = {1, 1};
    sfVector2f position = {100, 100};

    app->cursor = (cursor_t *)malloc(sizeof(cursor_t));
    app->cursor->scale = scale;
    app->cursor->position = position;
    app->cursor->sprite = sfSprite_create();
    app->cursor->texture_menu =
        sfTexture_createFromFile("assets/sprite/mouse.png", NULL);
    app->cursor->texture_game =
        sfTexture_createFromFile("assets/sprite/cursor.png", NULL);
    sfSprite_setScale(app->cursor->sprite, app->cursor->scale);
    sfSprite_setTexture(app->cursor->sprite,
        app->cursor->texture_menu, sfTrue);
}
