/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** set_view
*/

#include "my.h"

void set_view(app_t *app)
{
    sfVector2f size = {1920, 1080};
    sfVector2f center = {960, 540};

    app->view = malloc(sizeof(*(app->view)));
    app->view->size = size;
    app->view->center = center;
    app->view->view = sfView_create();
    sfView_setSize(app->view->view, app->view->size);
    sfView_setCenter(app->view->view, app->view->center);
}
