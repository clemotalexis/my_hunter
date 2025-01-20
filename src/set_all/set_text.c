/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** set_text
*/

#include "my.h"

static void set_score(app_t *app)
{
    app->text[2].font = sfFont_createFromFile("assets/OldGameFatty.ttf");
    app->text[3].font = sfFont_createFromFile("assets/OldGameFatty.ttf");
    app->text[2].text = sfText_create();
    app->text[3].text = sfText_create();
    sfText_setFont(app->text[2].text, app->text[2].font);
    sfText_setString(app->text[2].text, "Score : ");
    sfText_setColor(app->text[2].text, (sfColor){0, 0, 0, 255});
    sfText_setColor(app->text[3].text, (sfColor){0, 0, 0, 255});
    sfText_setCharacterSize(app->text[2].text, 40);
    sfText_setPosition(app->text[2].text, (sfVector2f){850, 880});
    sfText_setFont(app->text[3].text, app->text[1].font);
    sfText_setString(app->text[3].text, "0");
    sfText_setCharacterSize(app->text[3].text, 40);
    sfText_setPosition(app->text[3].text, (sfVector2f){1000, 880});
}

static void set_level(app_t *app)
{
    app->text[4].font = sfFont_createFromFile("assets/OldGameFatty.ttf");
    app->text[5].font = sfFont_createFromFile("assets/OldGameFatty.ttf");
    app->text[4].text = sfText_create();
    app->text[5].text = sfText_create();
    sfText_setFont(app->text[4].text, app->text[4].font);
    sfText_setString(app->text[4].text, "Difficulty : ");
    sfText_setColor(app->text[4].text, (sfColor){0, 0, 0, 255});
    sfText_setColor(app->text[5].text, (sfColor){0, 0, 0, 255});
    sfText_setCharacterSize(app->text[4].text, 40);
    sfText_setPosition(app->text[4].text, (sfVector2f){850, 980});
    sfText_setFont(app->text[5].text, app->text[1].font);
    sfText_setString(app->text[5].text, "1");
    sfText_setCharacterSize(app->text[5].text, 40);
    sfText_setPosition(app->text[5].text, (sfVector2f){1080, 980});
}

void set_text(app_t *app)
{
    app->text = malloc(sizeof(*(app->text)) * 6);
    app->text[0].font = sfFont_createFromFile("assets/OldGameFatty.ttf");
    app->text[1].font = sfFont_createFromFile("assets/OldGameFatty.ttf");
    app->text[0].text = sfText_create();
    app->text[1].text = sfText_create();
    sfText_setFont(app->text[0].text, app->text[0].font);
    sfText_setString(app->text[0].text, "Volume : ");
    sfText_setColor(app->text[0].text, (sfColor){100, 100, 100, 255});
    sfText_setColor(app->text[1].text, (sfColor){100, 100, 100, 255});
    sfText_setCharacterSize(app->text[0].text, 40);
    sfText_setPosition(app->text[0].text, (sfVector2f){850, 580});
    sfText_setFont(app->text[1].text, app->text[1].font);
    sfText_setString(app->text[1].text, "50");
    sfText_setCharacterSize(app->text[1].text, 40);
    sfText_setPosition(app->text[1].text, (sfVector2f){1030, 580});
    set_level(app);
    set_score(app);
}
