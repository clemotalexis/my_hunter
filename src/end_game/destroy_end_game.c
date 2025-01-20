/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** destroy_end_game
*/

#include "my.h"

void destroy_end_game(app_t *app)
{
    sfTexture_destroy(app->background->texture);
    sfSprite_destroy(app->background->sprite);
    for (int i = 0; i < 10; i++) {
        sfTexture_destroy(app->mob[i].texture);
        sfTexture_destroy(app->mob[i].texture_death);
        sfSprite_destroy(app->mob[i].sprite);
    }
}
