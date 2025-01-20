/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** set_music
*/

#include "my.h"

void set_music(app_t *app)
{
    app->song = malloc(sizeof(*(app->song)));
    app->song->music = sfMusic_createFromFile("assets/music/main_music.ogg");
    app->song->volume = 50;
    sfMusic_setVolume(app->song->music, app->song->volume);
    sfMusic_play(app->song->music);
    sfMusic_setLoop(app->song->music, sfTrue);
}
