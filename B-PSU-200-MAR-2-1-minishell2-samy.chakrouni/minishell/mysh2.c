/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-minishell2-samy.chakrouni
** File description:
** get_path
*/

#include <stdlib.h>
#include "my.h"

int remove_value(char *path)
{
    int i = 0;

    for (i = 0; path[i] != '='; i++);
    i++;
    return (i);
}

char **separate_paths(char *path)
{
    int nbr = count_args(path, ':');
    char **sep = malloc(sizeof(char *) * (nbr + 1));
    ar_t struc_args = {0};

    for (int j = 0; j < nbr; j++)
        sep[j] = malloc(sizeof(char) * (my_strlen(path) + 1));
    while (path[struc_args.i] != '\0') {
        if (path[struc_args.i] == ':') {
            sep[struc_args.j][struc_args.z] = '\0';
            struc_args.i++;
            struc_args.j++;
            struc_args.z = 0;
        } else {
            sep[struc_args.j][struc_args.z] = path[struc_args.i];
            struc_args.i++;
            struc_args.z++;
        }
    }
    sep[struc_args.j][struc_args.z] = '\0';
    return sep;
}
