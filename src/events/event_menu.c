/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** events_menu
*/

#include "my.h"
#include <stdio.h>

static void events_mouse(app_t *app)
{
    sfVector2i mouPiPos = sfMouse_getPositionRenderWindow(app->window->window);
    sfVector2f mouWPos = sfRenderWindow_mapPixelToCoords(app->window->window,
        mouPiPos, app->view->view);
    sfFloatRect bounds_play = sfSprite_getGlobalBounds(app->buttons[0].sprite);
    sfFloatRect bounds_opti = sfSprite_getGlobalBounds(app->buttons[1].sprite);
    sfFloatRect bounds_exit = sfSprite_getGlobalBounds(app->buttons[2].sprite);

    if (sfFloatRect_contains(&bounds_play, mouWPos.x, mouWPos.y)) {
        app->window->menu = 0;
        sfSprite_setScale(app->cursor->sprite, (sfVector2f){0.3, 0.3});
        sfSprite_setTexture(app->cursor->sprite, app->cursor->texture_game,
                sfTrue);
    }
    if (sfFloatRect_contains(&bounds_opti, mouWPos.x, mouWPos.y)) {
        app->window->menu = 2;
        app->buttons[2].position = (sfVector2f){840, 750};
        sfSprite_setPosition(app->buttons[2].sprite, app->buttons[2].position);
    }
    if (sfFloatRect_contains(&bounds_exit, mouWPos.x, mouWPos.y))
        sfRenderWindow_close(app->window->window);
}

void event_menu(sfEvent *event, app_t *app)
{
    sfVector2u size = sfRenderWindow_getSize(app->window->window);
    sfVector2u newSize;

    app->window->coef_x = (float)size.x / (float)app->window->video_mode.width;
    app->window->coef_y =
        (float)size.y / (float)app->window->video_mode.height;
    while (sfRenderWindow_pollEvent(app->window->window, event)) {
        if (event->type == sfEvtResized) {
            newSize.x = event->size.width;
            newSize.y = event->size.height;
            update_view(app->view->view, newSize);
        }
        if (event->type == sfEvtClosed) {
            sfRenderWindow_close(app->window->window);
        }
        if (event->type == sfEvtMouseButtonPressed) {
            events_mouse(app);
        }
    }
}
