/*
** EPITECH PROJECT, 2023
** check_assets
** File description:
** check assets
*/

#include <SFML/Graphics.h>

int check_assets(void)
{
    sfTexture *temp = sfTexture_createFromFile("assets/background.jpg", NULL);
    if (temp == NULL)
        return 84;

    temp = sfTexture_createFromFile("assets/plane.png", NULL);
    if (temp == NULL)
        return 84;

    temp = sfTexture_createFromFile("assets/tower.png", NULL);
    if (temp == NULL)
        return 84;

    sfFont *font = sfFont_createFromFile("assets/Minecraft.ttf");
    if (font == NULL)
        return 84;

    return 0;
}
