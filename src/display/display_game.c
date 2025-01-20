/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** display_all
*/

#include "my.h"

static void display_mobs(app_t *app, int nb_sprite)
{
    for (int i = 0; i != nb_sprite; i++) {
        sfSprite_setTextureRect(app->mob[i].sprite, app->mob[i].rect);
        sfRenderWindow_drawSprite(app->window->window,
            app->mob[i].sprite, NULL);
    }
}

static void display_mouse(app_t *app)
{
    sfVector2f mouse_position = get_corrected_mouse_position(app,
        app->window->window);

    mouse_position.x = mouse_position.x - (132.5 * 0.3);
    mouse_position.y = mouse_position.y - (132 * 0.3);
    sfSprite_setPosition(app->cursor->sprite, mouse_position);
    sfRenderWindow_drawSprite(app->window->window, app->cursor->sprite, NULL);
}

void display_game(sfRenderWindow *window, app_t *app)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, app->background->sprite, NULL);
    display_mobs(app, app->game->nb_sprite);
    sfRenderWindow_drawText(window, app->text[2].text, NULL);
    sfRenderWindow_drawText(window, app->text[3].text, NULL);
    sfRenderWindow_drawText(window, app->text[4].text, NULL);
    sfRenderWindow_drawText(window, app->text[5].text, NULL);
    display_mouse(app);
    sfRenderWindow_setView(window, app->view->view);
    sfRenderWindow_display(window);
}
