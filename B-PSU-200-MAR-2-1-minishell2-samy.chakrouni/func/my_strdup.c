/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include "my.h"
#include <unistd.h>

char *my_strdup(char const *src)
{
    int j = 0;
    char *dest;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (src[j] != '\0') {
        dest[j] = src[j];
        j++;
    }
    dest[j] = '\0';
    return dest;
}
