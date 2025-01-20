/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** set_window
*/

#include "my.h"
#include <SFML/Graphics.h>

void set_window(app_t *app)
{
    app->game->difficulty = 1;
    app->game->score = 0;
    app->game->i = 0;
    app->game->nb_sprite = 1;
    app->window = malloc(sizeof(*(app->window)));
    app->window->menu = 1;
    app->window->video_mode.bitsPerPixel =
        sfVideoMode_getDesktopMode().bitsPerPixel;
    app->window->video_mode.height = sfVideoMode_getDesktopMode().height;
    app->window->video_mode.width = sfVideoMode_getDesktopMode().width;
    app->window->window = sfRenderWindow_create(app->window->video_mode,
        "my_hunter", sfResize | sfClose, NULL);
    app->window->coef_x = app->window->video_mode.width;
    app->window->coef_y = app->window->video_mode.height;
    sfRenderWindow_setMouseCursorVisible(app->window->window, sfFalse);
    sfRenderWindow_setFramerateLimit(app->window->window, 60);
}
