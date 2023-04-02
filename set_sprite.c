/*
** EPITECH PROJECT, 2023
** set_sprite
** File description:
** set the sprite
*/

#include "include/plane_class.h"
#include "include/tower_class.h"
#include <math.h>

plane set_plane_sprite(plane p, float alpha)
{
    p.p_text = sfTexture_createFromFile("assets/plane.png", NULL);
    p.aircraft = sfSprite_create();
    sfSprite_setTexture(p.aircraft, p.p_text, sfTrue);

    sfSprite_setPosition(p.aircraft, p.start);
    sfSprite_setOrigin(p.aircraft, (sfVector2f){10, 10});
    sfSprite_setRotation(p.aircraft, (alpha * 180) / M_PI);

    p.hitbox = sfRectangleShape_create();
    sfRectangleShape_setFillColor(p.hitbox, sfTransparent);
    sfRectangleShape_setOutlineColor(p.hitbox, sfRed);
    sfRectangleShape_setOutlineThickness(p.hitbox, 0.9f);
    sfRectangleShape_setRotation(p.hitbox, (alpha * 180) / M_PI);
    sfRectangleShape_setPosition(p.hitbox, p.start);
    sfRectangleShape_setSize(p.hitbox, (sfVector2f){20, 20});
    sfRectangleShape_setOrigin(p.hitbox, (sfVector2f){10, 10});
    return p;
}

tower set_tower_sprite(tower t, float radius)
{
    t.t_text = sfTexture_createFromFile("assets/tower.png", NULL);
    t.tower = sfSprite_create();
    sfSprite_setTexture(t.tower, t.t_text, sfTrue);
    sfSprite_setPosition(t.tower, t.position);
    sfSprite_setOrigin(t.tower, (sfVector2f){15, 15});

    t.zone = sfCircleShape_create();
    sfCircleShape_setFillColor(t.zone, sfTransparent);
    sfCircleShape_setRadius(t.zone, radius);
    sfCircleShape_setOutlineColor(t.zone, sfCyan);
    sfCircleShape_setOutlineThickness(t.zone, 1);
    sfCircleShape_setOrigin(t.zone, (sfVector2f){radius, radius});
    sfCircleShape_setPosition(t.zone, t.position);

    return t;
}
