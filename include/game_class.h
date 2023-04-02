/*
** EPITECH PROJECT, 2023
** game class
** File description:
** ouais
*/

#ifndef game_class
    #define game_class

    #include <SFML/Graphics.h>
    #include <SFML/System.h>

    typedef struct game {

        sfRenderWindow *window;
        sfVideoMode mode;

        sfTexture *background_texture;
        sfSprite *background;

        sfClock *clock;
        sfTime time;
        float seconds;

        int nb_plane;
        int nb_plane_alive;
        int nb_tower;
        int show_hitbox;
        int show_sprite;

        sfText *text_l;
        sfText *text_s;
        sfText *text_q;
        sfFont *text_font;

    } game;

#endif /* game class */
