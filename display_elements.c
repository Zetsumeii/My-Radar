/*
** EPITECH PROJECT, 2023
** display elements
** File description:
** ouais
*/

#include "include/game_class.h"
#include "include/plane_class.h"
#include "include/tower_class.h"

void display_hitbox(plane p, game *main)
{
    if (main->show_hitbox == 1)
        sfRenderWindow_drawRectangleShape(main->window, p.hitbox, NULL);
}

void display_areas(tower t, game *main)
{
    if (main->show_hitbox == 1)
        sfRenderWindow_drawCircleShape(main->window, t.zone, NULL);
}

void display_planes(plane *p, game *main)
{
    for (int i = 0; i < main->nb_plane; i += 1) {
        if (main->seconds >= p[i].spawn && p[i].is_alive == 0 &&
                main->show_sprite == 1) {
            sfRenderWindow_drawSprite(main->window, p[i].aircraft, NULL);
        }
        if (main->seconds >= p[i].spawn && p[i].is_alive == 0 &&
                main->show_hitbox == 1)
            display_hitbox(p[i], main);
    }
}

void display_tower(tower *tw, game *main)
{
    for (int i = 0; i < main->nb_tower; i += 1) {
        if (main->show_sprite == 1) {
            sfRenderWindow_drawSprite(main->window, tw[i].tower, NULL);
        }
        display_areas(tw[i], main);
    }
}
