/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-minishell2-samy.chakrouni
** File description:
** mysh4
*/

#include <stdlib.h>
#include "my.h"

int find_c(char *b, int i)
{
    int nb = i;

    for (; b[i] != '\0'; i++) {
        if (b[i] != ' ' && b[i] != '\t') {
            nb = i;
            break;
        }
    }
    return (nb);
}

char *supprime_buf(char *buf)
{
    char *str = malloc(sizeof(char) * (my_strlen(buf) + 1));
    int i = find_c(buf, 0);
    int j = 0;

    while (buf[i] != '\0') {
        if ((buf[i] == ' ' || buf[i] == '\t') && (buf[i + 1] == ' '
            || buf[i + 1] == '\t')) {
            str[j] = ' ';
            j++;
            i = find_c(buf, i);
            i--;
        } else {
            str[j] = buf[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';
    return str;
}

char *supprime_1(char *buff)
{
    int i = 0;

    buff = supprime_buf(buff);
    for (i = 0; buff[i] != '\0'; i++)
        if (buff[i] == '\n') {
            buff[i] = '\0';
            break;
        }
    while (buff[i - 1] == ' ' || buff[i - 1] == '\t') {
        buff[i - 1] = '\0';
        i--;
    }
    buff[i] = '\0';
    return (buff);
}
