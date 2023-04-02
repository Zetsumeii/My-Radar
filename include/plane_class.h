/*
** EPITECH PROJECT, 2023
** plane_class
** File description:
** ouais
*/

#include <SFML/Graphics.h>

#ifndef plane_class
    #define plane_class

    typedef struct plane {

        sfVector2f start;
        sfVector2f end;
        sfVector2f move;

        double velocity;
        double time_travel;

        int is_alive;
        int in_control;

        int spawn;

        sfSprite *aircraft;
        sfTexture *p_text;
        sfRectangleShape *hitbox;

    } plane;


#endif /* plane_class */
