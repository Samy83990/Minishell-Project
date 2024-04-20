/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-minishell1-samy.chakrouni
** File description:
** my_strncmp
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include <string.h>

int my_strncmp(const char *str1, const char *str2, size_t n)
{
    while (n > 0 && *str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
        n--;
    }
    if (n == 0 || (*str1 == '\0' && *str2 == '\0'))
        return 0;
    else
        return 84;
}
