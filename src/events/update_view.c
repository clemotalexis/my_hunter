/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** update_view
*/

#include "my.h"
#include <stdbool.h>

void update_view(sfView *view, sfVector2u size)
{
    float windowRatio = (float)size.x / (float)size.y;
    float viewRatio = (float)sfView_getSize(view).x /
        (float)sfView_getSize(view).y;
    float sizeX = 1;
    float sizeY = 1;
    float posX = 0;
    float posY = 0;
    bool horizontalSpacing = true;

    if (windowRatio < viewRatio)
        horizontalSpacing = false;
    if (horizontalSpacing) {
        sizeX = viewRatio / windowRatio;
        posX = (1 - sizeX) / 2.f;
    } else {
        sizeY = windowRatio / viewRatio;
        posY = (1 - sizeY) / 2.f;
    }
    sfView_setViewport(view, (sfFloatRect){posX, posY, sizeX, sizeY});
}
