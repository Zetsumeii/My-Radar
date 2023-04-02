/*
** EPITECH PROJECT, 2023
** -hoption
** File description:
** ui
*/

#include "include/my.h"
#include <unistd.h>

void display_usage(void)
{
    char *buffer = get_script("instructions");
    for (int i = 0; buffer[i] != '\0'; i += 1) {
        write(1, &buffer[i], 1);
    }
}
