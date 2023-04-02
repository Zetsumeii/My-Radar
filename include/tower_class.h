/*
** EPITECH PROJECT, 2023
** tower class
** File description:
** ouais
*/

#include <SFML/Graphics.h>

#ifndef tower_class
    #define tower_class

    typedef struct tower {

        sfVector2f position;
        sfVector2f origin;

        double radius;

        sfSprite *tower;
        sfTexture *t_text;
        sfCircleShape *zone;

    } tower;


#endif /* tower class */
