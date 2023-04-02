/*
** EPITECH PROJECT, 2023
** radar
** File description:
** ouais
*/


#ifndef radarr
    #define radarr

    #include <SFML/Graphics.h>
    #include "game_class.h"
    #include "plane_class.h"
    #include "tower_class.h"

    tower *set_arr_tower(char *buffer, int nb_tower);
    plane *set_arr_plane(char *buffer, int nb_plane);

    tower set_tower_content(tower t, char *str);
    plane set_plane_content(plane p, char *str);

    game *setup_game(game *main);

    int check_assets(void);

    plane set_plane_sprite(plane p, float alpha);
    tower set_tower_sprite(tower t, float radius);
    plane *update_plane_position(plane *pl, game *main);
    void check_destination(plane *pl, game *main);

    void display_planes(plane *pl, game *main);
    void display_tower(tower *tw, game *main);

    int plane_collision(plane plane1, plane plane2);
    int plane_in_tower_control(plane p, tower t);
    void check_collision(plane *plane, tower *tower, game *game);

    void clean_my_radar(game *game, plane *arr_plane, tower *arr_tower);
    int check_script(char *buffer);
    void display_usage(void);
    void display_error(void);

    game *setup_string(game *main);
    void display_instructions(game *main);

#endif /* radar */
