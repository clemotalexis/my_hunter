/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** events
*/

#include "my.h"
#include <stdio.h>

static void animation_death(app_t *app, sfVector2f currentPos,
    sfVector2f scale, int i)
{
    currentPos = sfSprite_getPosition(app->mob[i].sprite);
    app->mob[i].life = 0;
    app->mob[i].scale = scale;
    app->mob[i].position.x = currentPos.x - 20;
    app->mob[i].position.y = currentPos.y - 15;
    sfSprite_setTexture(app->mob[i].sprite, app->mob[i].texture_death, sfTrue);
    app->mob[i].rect.top = 0;
    app->mob[i].rect.left = 0;
    app->mob[i].rect.width = 96;
    app->mob[i].rect.height = 76.4;
    sfSprite_setPosition(app->mob[i].sprite, app->mob[i].position);
    sfSprite_setScale(app->mob[i].sprite, app->mob[i].scale);
    sfSprite_setTextureRect(app->mob[i].sprite, app->mob[i].rect);
}

static void calculate_total_sprite(app_t *app)
{
    char *difficulty;

    if (app->game->score > 0 && app->game->score % 5 == 0 &&
        app->game->nb_sprite < 10) {
        app->game->nb_sprite++;
        difficulty = int_to_char(app->game->nb_sprite);
        sfText_setString(app->text[5].text, difficulty);
        app->mob->speed = app->mob->speed + 1;
    }
}

static void events_mouse(app_t *app)
{
    sfVector2i PixelPos = sfMouse_getPositionRenderWindow(app->window->window);
    sfVector2f mouseWorldPos = sfRenderWindow_mapPixelToCoords
        (app->window->window, PixelPos, app->view->view);
    sfFloatRect bounds_mob;
    sfVector2f scale = {1.25, 1.25};
    sfVector2f currentPos;
    char *score;

    for (int i = 0; i < app->game->nb_sprite; i++) {
        bounds_mob = sfSprite_getGlobalBounds(app->mob[i].sprite);
        if (sfFloatRect_contains(&bounds_mob,
            mouseWorldPos.x, mouseWorldPos.y)) {
            app->game->score += 1;
            calculate_total_sprite(app);
            score = int_to_char(app->game->score);
            sfText_setString(app->text[3].text, score);
            animation_death(app, currentPos, scale, i);
            break;
        }
    }
}

void event_game(sfEvent *event, app_t *app)
{
    sfVector2u sze = sfRenderWindow_getSize(app->window->window);

    app->window->coef_x = (float)sze.x / (float)app->window->video_mode.width;
    app->window->coef_y = (float)sze.y / (float)app->window->video_mode.height;
    set_clock(app);
    while (sfRenderWindow_pollEvent(app->window->window, event)) {
        if (event->type == sfEvtResized)
            update_view(app->view->view, (sfVector2u){event->size.width,
                event->size.height});
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(app->window->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            app->window->menu = 1;
            sfSprite_setScale(app->cursor->sprite, (sfVector2f){1, 1});
            sfSprite_setTexture(app->cursor->sprite, app->cursor->texture_menu,
                sfTrue);
        }
        if (event->type == sfEvtMouseButtonPressed)
            events_mouse(app);
    }
}
