/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** main
*/

#include "my.h"
#include <stdio.h>


static void help_suit(void)
{
    write(1, "|       how to play: click on the monster with your mouse to"
            " kill it.       |\n", 78);
        write(1, "|         You can pause the game by pressing echap on your k"
            "eyboard,        |\n", 78);
        write(1, "|           you have access in the menu to an option screen "
            "which           |\n", 78);
        write(1, "|             allows you to change the volume of the game mu"
            "sic,            |\n", 78);
        write(1, "|                        to quit the game press 'exit'.     "
            "                |\n", 78);
        write(1, "|                                   __                      "
            "                |\n", 78);
        write(1, "|                                 <(o )___                  "
            "                |\n", 78);
        write(1, "|                                  ( ._> /                  "
            "                |\n", 78);
        write(1, "|                                   '---'                   "
            "                |\n", 78);
        write(1, "============================================================"
            "=================\n", 78);
}

static void help(int argc, char **argv)
{
    if (my_strcmp(argv[1], "-h") == 0) {
        write(1, "================================= my_hunter ================"
            "=================\n", 78);
        write(1, "|                                                           "
            "                |\n", 78);
        write(1, "|      This game is inspired by the 'Duck Hunt' game creat"
        "ed in 1984.       |\n", 78);
        write(1, "|      The objective of the game is to get the highest score"
            " possible,      |\n", 78);
        write(1, "|       you have three lives when a monster leaves the scree"
            "n before        |\n", 78);
        write(1, "|  you kill it you lose one life, if you have no more lives "
            "you have lost.  |\n", 78);
        write(1, "|                                                           "
            "                |\n", 78);
        write(1, "|                                How to play:               "
            "                |\n", 78);
        help_suit();
    }
}

static void loop(void)
{
    app_t app;
    sfEvent event;

    app.crea_clock = malloc(sizeof(crea_clock_t));
    set_all(&app);
    app.crea_clock->clock = sfClock_create();
    while (sfRenderWindow_isOpen(app.window->window)) {
        if (app.window->menu == 0) {
            event_game(&event, &app);
            display_game(app.window->window, &app);
        }
        if (app.window->menu == 1) {
            event_menu(&event, &app);
            display_menu(&app);
        }
        if (app.window->menu == 2) {
            event_options(&event, &app);
            display_options(&app);
        }
    }
}

int main(int argc, char **argv)
{
    if (argc == 1) {
        loop();
    } else {
        help(argc, argv);
    }
    sfWindow_destroy(NULL);
    return 0;
}
