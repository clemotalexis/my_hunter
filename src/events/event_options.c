/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** event_options
*/

#include "my.h"
#include <stdio.h>

static void events_volume(sfVector2f mouseWorldPos, sfFloatRect bound_minus,
    sfFloatRect bound_plus, app_t *app)
{
    char *volume;

    if (sfFloatRect_contains(&bound_minus, mouseWorldPos.x, mouseWorldPos.y)) {
        if (app->song->volume != 0) {
            app->song->volume -= 10;
            volume = int_to_char(app->song->volume);
            sfText_setString(app->text[1].text, volume);
            sfMusic_setVolume(app->song->music, app->song->volume);
        }
    }
    if (sfFloatRect_contains(&bound_plus, mouseWorldPos.x, mouseWorldPos.y)) {
        if (app->song->volume != 100) {
            app->song->volume += 10;
            volume = int_to_char(app->song->volume);
            sfText_setString(app->text[1].text, volume);
            sfMusic_setVolume(app->song->music, app->song->volume);
        }
    }
}

static void events_mouse(app_t *app)
{
    sfVector2i mousePixelPos = sfMouse_getPositionRenderWindow
        (app->window->window);
    sfVector2f mouseWorldPos = sfRenderWindow_mapPixelToCoords
        (app->window->window, mousePixelPos, app->view->view);
    sfFloatRect bounds_play = sfSprite_getGlobalBounds(app->buttons[0].sprite);
    sfFloatRect bounds_options =
        sfSprite_getGlobalBounds(app->buttons[1].sprite);
    sfFloatRect bounds_exit = sfSprite_getGlobalBounds(app->buttons[2].sprite);
    sfFloatRect bound_minus = sfSprite_getGlobalBounds(app->buttons[3].sprite);
    sfFloatRect bound_plus = sfSprite_getGlobalBounds(app->buttons[4].sprite);
    sfVector2f position = {85, 610};

    if (sfFloatRect_contains(&bounds_exit, mouseWorldPos.x, mouseWorldPos.y)) {
        app->window->menu = 1;
        app->buttons[2].position = position;
        sfSprite_setPosition(app->buttons[2].sprite, app->buttons[2].position);
    }
    events_volume(mouseWorldPos, bound_minus, bound_plus, app);
}

void event_options(sfEvent *event, app_t *app)
{
    sfVector2u size = sfRenderWindow_getSize(app->window->window);

    app->window->coef_x = (float)size.x / (float)app->window->video_mode.width;
    app->window->coef_y =
        (float)size.y / (float)app->window->video_mode.height;
    while (sfRenderWindow_pollEvent(app->window->window, event)) {
        if (event->type == sfEvtResized) {
            update_view(app->view->view,
                (sfVector2u){event->size.width, event->size.height});
        }
        if (event->type == sfEvtClosed) {
            sfRenderWindow_close(app->window->window);
        }
        if (event->type == sfEvtMouseButtonPressed) {
            events_mouse(app);
        }
    }
}
