/*
** EPITECH PROJECT, 2022
** clean
** File description:
** free and destroy
*/

#include "include/game_class.h"
#include "include/plane_class.h"
#include "include/tower_class.h"
#include <stdlib.h>

void clean_game_t(game *game)
{
    sfRenderWindow_destroy(game->window);
    sfSprite_destroy(game->background);
    sfTexture_destroy(game->background_texture);
    sfText_destroy(game->text_l);
    sfText_destroy(game->text_s);
    sfText_destroy(game->text_q);
    sfFont_destroy(game->text_font);

    sfClock_destroy(game->clock);
    free(game);
}

void clean_arr_plane(plane *arr_plane, int nb_plane)
{
    for (int i = 0; i < nb_plane; i += 1) {
        sfSprite_destroy(arr_plane[i].aircraft);
        sfTexture_destroy(arr_plane[i].p_text);
        sfRectangleShape_destroy(arr_plane[i].hitbox);
    }
    free(arr_plane);
}

void clean_arr_tower(tower *arr_tower, int nb_tower)
{
    for (int i = 0; i < nb_tower; i += 1) {
        sfSprite_destroy(arr_tower[i].tower);
        sfTexture_destroy(arr_tower[i].t_text);
        sfCircleShape_destroy(arr_tower[i].zone);
    }
    free(arr_tower);
}

void clean_my_radar(game *game, plane *arr_plane, tower *arr_tower)
{
    clean_arr_tower(arr_tower, game->nb_tower);
    clean_arr_plane(arr_plane, game->nb_plane);
    clean_game_t(game);
}
