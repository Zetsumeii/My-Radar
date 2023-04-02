/*
** EPITECH PROJECT, 2022
** collision
** File description:
** ouais
*/

#include "include/plane_class.h"
#include "include/tower_class.h"
#include "include/game_class.h"
#include <math.h>

int plane_collision(plane plane1, plane plane2);
int plane_in_tower_control(plane plane, tower tower);

plane check_tower(plane plane, tower *tower, game *game)
{
    for (int j = 0; j < game->nb_tower; j += 1) {
        if (plane_in_tower_control(plane, tower[j]) == 0) {
            plane.in_control = 1;
            sfRectangleShape_setOutlineColor(plane.hitbox, sfGreen);
            return plane;
        } else {
            plane.in_control = -1;
            sfRectangleShape_setOutlineColor(plane.hitbox, sfRed);
        }
    }
    return plane;
}

void check_plane(plane *pl, int i, int j, game *game)
{
    if (game->seconds >= pl[i].spawn && game->seconds >= pl[j].spawn &&
            pl[i].is_alive == 0 && pl[j].is_alive == 0 &&
            (pl[i].in_control != 1 && pl[j].in_control != 1)) {
        if (plane_collision(pl[i], pl[j]) == 1) {
            pl[i].is_alive = -1;
            pl[j].is_alive = -1;
            game->nb_plane_alive -= 2;
        }
    }

}

void check_collision(plane *plane, tower *tower, game *game)
{
    for (int i = 0; i < game->nb_plane; i += 1)
        plane[i] = check_tower(plane[i], tower, game);
    for (int i = 0; i < game->nb_plane - 1; i += 1) {
        for (int j = i + 1; j < game->nb_plane; j += 1)
            check_plane(plane, i, j, game);
    }
}
