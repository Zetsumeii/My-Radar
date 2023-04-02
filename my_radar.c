/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** collision gestion
*/

#include "include/my.h"
#include "include/my_radar_include.h"
#include "include/game_class.h"
#include "include/plane_class.h"
#include "include/tower_class.h"
#include <stdlib.h>
#include <unistd.h>

void window_check_event(sfEvent *event, game *main)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(main->window);
    if (event->type == sfEvtKeyPressed) {
        sfKeyEvent tmp = event->key;
        if (tmp.code == sfKeyQ || tmp.code == sfKeyEscape)
            sfRenderWindow_close(main->window);
        if (tmp.code == sfKeyL)
            main->show_hitbox *= -1;
        if (tmp.code == sfKeyS)
            main->show_sprite *= -1;
    }
}

void game_loop(plane *pl, tower *tw, game *main)
{
    main->time = sfClock_getElapsedTime(main->clock);
    main->seconds = main->time.microseconds / 1000000.f;

    sfEvent event;
    while (sfRenderWindow_pollEvent(main->window, &event))
        window_check_event(&event, main);

    sfRenderWindow_clear(main->window, sfBlack);
    sfRenderWindow_drawSprite(main->window, main->background, NULL);
    display_instructions(main);
    update_plane_position(pl, main);
    check_collision(pl, tw, main);
    check_destination(pl, main);
    display_planes(pl, main);
    display_tower(tw, main);

    sfRenderWindow_display(main->window);
}

int game_function(plane *pl, tower *tw, game *main)
{
    if (!main->window)
        return 84;

    main = setup_string(main);
    main->clock = sfClock_create();
    while (sfRenderWindow_isOpen(main->window) && main->nb_plane_alive > 0) {
        game_loop(pl, tw, main);
    }
    return 0;
}

int setup_my_radar(char *filepath)
{
    game *main = setup_game(main);
    char *buffer = get_script(filepath);

    if (main == NULL || buffer == NULL) {
        free(main); free(buffer); display_error(); return 84;
    }
    if (check_script(buffer) == 84) {
        free(buffer); free(main); display_error(); return 84;
    }

    main->nb_plane = find_n(buffer, 'A');
    main->nb_tower = find_n(buffer, 'T');
    main->nb_plane_alive = find_n(buffer, 'A');
    plane *pl = set_arr_plane(buffer, main->nb_plane);
    tower *tw = set_arr_tower(buffer, main->nb_tower);
    free(buffer);
    game_function(pl, tw, main);
    clean_my_radar(main, pl, tw);
    return 0;
}

int main(int argc, char **argv)
{
    if (check_args(argc, argv) != 0) {
        display_error();
        return 84;
    }
    if (my_strcmp(argv[1], "-h") == 0) {
        display_usage();
        return 0;
    }
    if (check_assets() != 0)
        return 84;

    return setup_my_radar(argv[1]);
}
