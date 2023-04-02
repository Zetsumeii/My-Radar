/*
** EPITECH PROJECT, 2023
** set_array
** File description:
** ouais
*/

#include "include/my_radar_include.h"
#include "include/plane_class.h"
#include "include/tower_class.h"
#include "include/my.h"
#include <stdlib.h>
#include <math.h>

plane set_plane_content(plane p, char *str)
{
    int idx = 0;
    p.start.x = my_special_getnbr(str, &idx);
    p.start.y = my_special_getnbr(str, &idx);
    p.end.x = my_special_getnbr(str, &idx);
    p.end.y = my_special_getnbr(str, &idx);
    p.velocity = my_special_getnbr(str, &idx);
    p.spawn = my_special_getnbr(str, &idx);
    float alpha = atanf((p.end.y - p.start.y) / (p.end.x - p.start.x));
    float d = sqrtf(pow(p.end.x - p.start.x, 2) + pow(p.end.y - p.start.y, 2));
    p.move.x = cosf(alpha) * p.velocity;
    p.move.y = sinf(alpha) * p.velocity;
    p.time_travel = (d / p.velocity) + p.spawn;
    p.is_alive = 0;
    p.in_control = -1;
    p = set_plane_sprite(p, alpha);
    sfSprite_setRotation(p.aircraft, (alpha * 180) / M_PI);
    return p;
}

tower set_tower_content(tower t, char *str)
{
    int idx = 0;
    t.position.x = my_special_getnbr(str, &idx);
    t.position.y = my_special_getnbr(str, &idx);
    t.radius = (1920.f / 100) * my_special_getnbr(str, &idx);
    t = set_tower_sprite(t, t.radius);
    return t;
}

plane *set_arr_plane(char *buffer, int nb_plane)
{
    plane *arr_plane = malloc(sizeof(plane) * nb_plane);
    if (arr_plane == NULL)
        return NULL;
    char **script = my_split(buffer, '\n');
    int p = 0;
    for (int i = 0; script[i] != NULL; i += 1) {
        int index = 0;
        if (script[i][0] == 'A') {
            arr_plane[p] = set_plane_content(arr_plane[p], script[i]);
            p += 1;
        }
    }
    return arr_plane;
}

tower *set_arr_tower(char *buffer, int nb_tower)
{
    tower *arr_tower = malloc(sizeof(tower) * nb_tower);
    if (arr_tower == NULL)
        return NULL;
    char **script = my_split(buffer, '\n');
    int p = 0;
    for (int i = 0; script[i] != NULL; i += 1) {
        int index = 0;
        if (script[i][0] == 'T') {
            arr_tower[p] = set_tower_content(arr_tower[p], script[i]);
            p += 1;
        }
    }
    return arr_tower;
}
