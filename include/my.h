/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** my
*/

#include "struct.h"
#include <unistd.h>
#include <stdlib.h>

#ifndef MY_H_
    #define MY_H_

//lib---------------------------
char *int_to_char(int n);
int my_strcmp(char const *s1, char const *s2);
//------------------------------

//src/events--------------------
void event_game(sfEvent *event, app_t *app);
void event_menu(sfEvent *event, app_t *app);
void event_options(sfEvent *event, app_t *app);
void update_view(sfView *view, sfVector2u size);
sfVector2f get_corrected_mouse_position(app_t *app, sfRenderWindow *window);
//------------------------------

//src/display-------------------
void display_game(sfRenderWindow *window, app_t *app);
void display_menu(app_t *app);
void display_options(app_t *app);
//------------------------------

//src/set_all-------------------
void set_all(app_t *app);
void set_window(app_t *app);
void set_mob(app_t *app);
void set_music(app_t *app);
void set_cursor(app_t *app);
void set_back_menu(app_t *app);
void set_back_game(app_t *app);
void set_buttons(app_t *app);
void set_text(app_t *app);
void set_view(app_t *app);
//------------------------------

//src/clock---------------------
void set_clock(app_t *app);
//------------------------------

//src/destroy-------------------
void destroy_end_game(app_t *app);
//------------------------------



#endif
