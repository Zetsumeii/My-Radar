/*
** EPITECH PROJECT, 2023
** eroro
** File description:
** ui
*/

#include <unistd.h>

void display_error(void)
{
    write(2, "./my_radar: bad arguments: 0 given but 84 is required\n", 55);
    write(2, "retry with -h\n", 15);
}
