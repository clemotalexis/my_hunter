/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** get_corrected_mouse_position
*/

#include "my.h"

sfVector2f get_corrected_mouse_position(app_t *app, sfRenderWindow *window)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(window);
    sfVector2f worldPos = sfRenderWindow_mapPixelToCoords(window, pixelPos,
        app->view->view);

    return worldPos;
}
