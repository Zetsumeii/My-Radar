/*
** EPITECH PROJECT, 2023
** collision
** File description:
** ouais
*/

#include <math.h>
#include "include/plane_class.h"
#include "include/tower_class.h"
#include "include/game_class.h"

int plane_collision(plane plane1, plane plane2)
{
    sfVector2f plane1_pos = sfSprite_getPosition(plane1.aircraft);
    sfVector2f plane2_pos = sfSprite_getPosition(plane2.aircraft);

    if (plane1_pos.x < plane2_pos.x + 20 &&
            plane1_pos.x + 20 > plane2_pos.x &&
            plane1_pos.y < plane2_pos.y + 20 &&
            20 + plane1_pos.y > plane2_pos.y) {
        return 1;
    }
    return 0;
}

int plane_in_tower_control(plane plane, tower tower)
{
    sfVector2f circle = tower.position;
    sfVector2f rect = sfSprite_getPosition(plane.aircraft);
    float temp_x = circle.x;
    float temp_y = circle.y;
    if (circle.x < rect.x)
        temp_x = rect.x;
    else if (circle.x > rect.x + 10.f)
        temp_x = rect.x + 10.f;
    if (circle.y < rect.y)
        temp_y = rect.y;
    else if (circle.y > rect.y + 10.f)
        temp_y = rect.y + 10.f;
    float distanceX = circle.x - temp_x;
    float distanceY = circle.y - temp_y;
    float distance = sqrtf(pow(distanceX, 2) + pow(distanceY, 2));
    if (distance < tower.radius)
        return 0;
    return -1;
}
