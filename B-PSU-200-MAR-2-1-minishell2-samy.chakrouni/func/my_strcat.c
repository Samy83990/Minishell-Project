/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-minishell2-samy.chakrouni
** File description:
** my_strcat
*/

#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    char *end = malloc(my_strlen(dest) + my_strlen(src) + 1);

    my_strcpy(end, dest);
    my_strcpy(end + my_strlen(dest), src);
    return end;
}
