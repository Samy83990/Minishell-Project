/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-minishell2-samy.chakrouni
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
    int Z = 0;

    while (src[Z] != '\0') {
        dest[Z] = src[Z];
        Z++;
    }
    dest[Z] = '\0';
    return 0;
}
