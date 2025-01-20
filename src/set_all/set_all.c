/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** set_all
*/

#include "my.h"

void set_all(app_t *app)
{
    app->game = malloc(sizeof(*(app->game)));
    set_window(app);
    set_view(app);
    set_music(app);
    set_mob(app);
    set_cursor(app);
    set_buttons(app);
    set_back_game(app);
    set_back_menu(app);
    set_text(app);
}
