/*
** EPITECH PROJECT, 2022
** my_strupcase
** File description:
** ouais
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if (str[i] == ' ')
            i++;
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
    return (str);
}
