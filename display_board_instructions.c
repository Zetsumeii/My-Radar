/*
** EPITECH PROJECT, 2023
** radar
** File description:
** ui
*/

#include "include/my.h"
#include "include/game_class.h"

game *setup_string(game *m)
{
    char *str_l = "Press l to turn off hitbox display";
    char *str_s = "Press S to turn off sprite display";
    char *str_q = "Press Q or Espace to leave the game";
    m->text_l = sfText_create(); m->text_s = sfText_create();
    m->text_q = sfText_create();
    m->text_font = sfFont_createFromFile("assets/Minecraft.ttf");
    sfText_setString(m->text_l, str_l);
    sfText_setString(m->text_s, str_s);sfText_setString(m->text_q, str_q);
    sfText_setFont(m->text_l, m->text_font);
    sfText_setFont(m->text_s, m->text_font);
    sfText_setFont(m->text_q, m->text_font);
    sfText_setCharacterSize(m->text_l, 30);
    sfText_setCharacterSize(m->text_s, 30);
    sfText_setCharacterSize(m->text_q, 30);
    sfText_setColor(m->text_l, sfBlue);
    sfText_setColor(m->text_s, sfBlue);
    sfText_setColor(m->text_q, sfCyan);
    sfText_setPosition(m->text_l, (sfVector2f){0, 0});
    sfText_setPosition(m->text_s, (sfVector2f){640, 0});
    sfText_setPosition(m->text_q, (sfVector2f){1280, 0}); return m;
}

void display_instructions(game *main)
{
    if (main->show_hitbox == 1)
        sfText_setColor(main->text_l, sfBlue);
    else
        sfText_setColor(main->text_l, sfRed);

    if (main->show_sprite == 1)
        sfText_setColor(main->text_s, sfBlue);
    else
        sfText_setColor(main->text_s, sfRed);

    sfRenderWindow_drawText(main->window, main->text_l, NULL);
    sfRenderWindow_drawText(main->window, main->text_s, NULL);
    sfRenderWindow_drawText(main->window, main->text_q, NULL);
}
