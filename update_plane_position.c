/*
** EPITECH PROJECT, 2023
** update plane
** File description:
** ouais
*/

#include "include/plane_class.h"
#include "include/game_class.h"

plane *update_plane_position(plane *pl, game *main)
{
    for (int i = 0; i < main->nb_plane; i += 1) {
        if (main->seconds >= pl[i].spawn && pl[i].is_alive == 0) {

            float x = pl[i].start.x;
            float y = pl[i].start.y;

            x += (main->seconds - pl[i].spawn) * pl[i].move.x;
            y += (main->seconds - pl[i].spawn) * pl[i].move.y;

            sfSprite_setPosition(pl[i].aircraft, (sfVector2f){x, y});
            sfRectangleShape_setPosition(pl[i].hitbox, (sfVector2f){x, y});
        }
    }
    return pl;
}

void check_destination(plane *pl, game *main)
{
    for (int i = 0; i < main->nb_plane; i += 1) {
        if (main->seconds >= pl[i].time_travel && pl[i].is_alive == 0) {
            pl[i].is_alive = -1;
            main->nb_plane_alive -= 1;
        }
    }
}
