/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** set_buttons
*/

#include "my.h"

static void set_rect_play(app_t *app)
{
    app->buttons[0].rect.top = 20;
    app->buttons[0].rect.left = 31;
    app->buttons[0].rect.width = 395;
    app->buttons[0].rect.height = 153;
}

static void set_rect_options(app_t *app)
{
    app->buttons[1].rect.top = 182;
    app->buttons[1].rect.left = 31;
    app->buttons[1].rect.width = 395;
    app->buttons[1].rect.height = 153;
}

static void set_rect_exit(app_t *app)
{
    app->buttons[2].rect.top = 340;
    app->buttons[2].rect.left = 31;
    app->buttons[2].rect.width = 395;
    app->buttons[2].rect.height = 153;
}

static void set_buttons_play(app_t *app)
{
    sfVector2f scale = {0.6, 0.6};
    sfVector2f position = {85, 340};

    app->buttons[0].scale = scale;
    app->buttons[0].position = position;
    app->buttons[0].sprite = sfSprite_create();
    app->buttons[0].texture =
        sfTexture_createFromFile("assets/sprite/button_play.png", NULL);
    set_rect_play(app);
    sfSprite_setPosition(app->buttons[0].sprite, app->buttons[0].position);
    sfSprite_setScale(app->buttons[0].sprite, app->buttons[0].scale);
    sfSprite_setTexture(app->buttons[0].sprite, app->buttons[0].texture,
        sfTrue);
}

static void set_buttons_options(app_t *app)
{
    sfVector2f scale = {0.6, 0.6};
    sfVector2f position = {85, 480};

    app->buttons[1].scale = scale;
    app->buttons[1].position = position;
    app->buttons[1].sprite = sfSprite_create();
    app->buttons[1].texture =
        sfTexture_createFromFile("assets/sprite/button_options.png", NULL);
    set_rect_options(app);
    sfSprite_setPosition(app->buttons[1].sprite, app->buttons[1].position);
    sfSprite_setScale(app->buttons[1].sprite, app->buttons[1].scale);
    sfSprite_setTexture(app->buttons[1].sprite, app->buttons[1].texture,
        sfTrue);
}

static void set_buttons_exit(app_t *app)
{
    sfVector2f scale = {0.6, 0.6};
    sfVector2f position = {85, 610};

    app->buttons[2].scale = scale;
    app->buttons[2].position = position;
    app->buttons[2].sprite = sfSprite_create();
    app->buttons[2].texture =
        sfTexture_createFromFile("assets/sprite/button_exit.png", NULL);
    set_rect_exit(app);
    sfSprite_setPosition(app->buttons[2].sprite, app->buttons[2].position);
    sfSprite_setScale(app->buttons[2].sprite, app->buttons[2].scale);
    sfSprite_setTexture(app->buttons[2].sprite, app->buttons[2].texture,
        sfTrue);
}

static void set_buttons_minus(app_t *app)
{
    sfVector2f scale = {0.4, 0.4};
    sfVector2f position = {1190, 560};

    app->buttons[3].scale = scale;
    app->buttons[3].position = position;
    app->buttons[3].sprite = sfSprite_create();
    app->buttons[3].texture =
        sfTexture_createFromFile("assets/sprite/minus.png", NULL);
    app->buttons[3].rect.top = 84;
    app->buttons[3].rect.left = 272;
    app->buttons[3].rect.width = 209;
    app->buttons[3].rect.height = 233;
    sfSprite_setPosition(app->buttons[3].sprite, app->buttons[3].position);
    sfSprite_setScale(app->buttons[3].sprite, app->buttons[3].scale);
    sfSprite_setTexture(app->buttons[3].sprite, app->buttons[3].texture,
        sfTrue);
}

static void set_buttons_plus(app_t *app)
{
    sfVector2f scale = {0.4, 0.4};
    sfVector2f position = {650, 560};

    app->buttons[4].scale = scale;
    app->buttons[4].position = position;
    app->buttons[4].sprite = sfSprite_create();
    app->buttons[4].texture =
        sfTexture_createFromFile("assets/sprite/plus.png", NULL);
    app->buttons[4].rect.top = 82;
    app->buttons[4].rect.left = 16;
    app->buttons[4].rect.width = 209;
    app->buttons[4].rect.height = 233;
    sfSprite_setPosition(app->buttons[4].sprite, app->buttons[4].position);
    sfSprite_setScale(app->buttons[4].sprite, app->buttons[4].scale);
    sfSprite_setTexture(app->buttons[4].sprite, app->buttons[4].texture,
        sfTrue);
}

void set_buttons(app_t *app)
{
    app->buttons = malloc(sizeof(*(app->buttons)) * 5);
    set_buttons_play(app);
    set_buttons_options(app);
    set_buttons_exit(app);
    set_buttons_plus(app);
    set_buttons_minus(app);
}
