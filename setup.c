/*
** EPITECH PROJECT, 2023
** setup
** File description:
** ouais
*/

#include "include/game_class.h"
#include <stdlib.h>

game *setup_game(game *main)
{
    main = malloc(sizeof(game));
    if (main == NULL)
        return NULL;
    main->mode.bitsPerPixel = 32;
    main->mode.height = 1080;
    main->mode.width = 1920;
    main->window = sfRenderWindow_create(main->mode, "radar", sfResize
            | sfClose, NULL);
    main->background_texture = sfTexture_createFromFile("assets/background.jpg"
            , NULL);
    if (main->background_texture == NULL)
        return NULL;
    sfRenderWindow_setFramerateLimit(main->window, 60);
    main->background = sfSprite_create();
    main->show_hitbox = 1; main->show_sprite = 1;
    sfSprite_setTexture(main->background, main->background_texture, sfTrue);
    sfSprite_setPosition(main->background, (sfVector2f){0, 0});
    main->clock = sfClock_create();
    return main;
}
