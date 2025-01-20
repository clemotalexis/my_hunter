/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** display_options
*/

#include "my.h"

static void display_mouse(app_t *app)
{
    sfVector2f mouse_position = get_corrected_mouse_position(app,
        app->window->window);

    sfSprite_setPosition(app->cursor->sprite, mouse_position);
    sfRenderWindow_drawSprite(app->window->window, app->cursor->sprite, NULL);
}

void display_options(app_t *app)
{
    sfRenderWindow_clear(app->window->window, sfBlack);
    sfSprite_setTextureRect(app->buttons[3].sprite, app->buttons[3].rect);
    sfSprite_setTextureRect(app->buttons[4].sprite, app->buttons[4].rect);
    sfRenderWindow_drawSprite(app->window->window,
        app->background[1].sprite, NULL);
    sfRenderWindow_drawSprite(app->window->window,
        app->buttons[3].sprite, NULL);
    sfRenderWindow_drawSprite(app->window->window,
        app->buttons[4].sprite, NULL);
    sfRenderWindow_drawSprite(app->window->window,
        app->buttons[2].sprite, NULL);
    sfRenderWindow_drawText(app->window->window, app->text[0].text, NULL);
    sfRenderWindow_drawText(app->window->window, app->text[1].text, NULL);
    display_mouse(app);
    sfRenderWindow_setView(app->window->window, app->view->view);
    sfRenderWindow_display(app->window->window);
}
