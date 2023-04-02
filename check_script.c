/*
** EPITECH PROJECT, 2023
** error handling
** File description:
** check the user input
*/

#include "include/my.h"
#include <stdlib.h>
#include <stdio.h>

int count_words(char *str)
{
    int c = 0;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] != ' ' && (str[i + 1] == ' ') || str[i + 1] == '\t')
            c += 1;
    }
    return c + 1;
}

int verif_char(char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (is_num(str[i]) == 0 && str[i] != 'A' && str[i] != 'T' &&
                str[i] != ' ' && str[i] != '\t')
            return 84;
    }
    return 0;
}

int check_script(char *buffer)
{
    int WORDS_COUNT = 0;
    char **script = my_split(buffer, '\n');
    for (int i = 0; script[i] != NULL; i += 1) {
        WORDS_COUNT = count_words(script[i]);
        if (WORDS_COUNT != 7 && WORDS_COUNT != 4)
            return 84;
        if (verif_char(script[i]) == 84)
            return 84;
    }
    return 0;
}
