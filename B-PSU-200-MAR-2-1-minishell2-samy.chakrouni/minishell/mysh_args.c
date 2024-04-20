/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-minishell2-samy.chakrouni
** File description:
** get_args
*/

#include <stdlib.h>
#include "my.h"

int count_args(char *buff, char sep)
{
    int nbr = 1;

    for (int i = 0; buff[i] != '\0'; i++)
        if (buff[i] == sep)
            nbr++;
    return (nbr);
}

void get_args(get_sh_t *st, char *buff)
{
    ar_t struc_args = {0};
    int nbr = count_args(buff, ' ');

    st->array = malloc(sizeof(char *) * (nbr + 2));
    for (int a = 0; a < nbr; a++)
        st->array[a] = malloc(sizeof(char) * (my_strlen(buff) + 1));
    while (buff[struc_args.i] != '\0') {
        if (buff[struc_args.i] == ' ') {
            st->array[struc_args.j][struc_args.z] = '\0';
            struc_args.i++;
            struc_args.j++;
            struc_args.z = 0;
        } else {
            st->array[struc_args.j][struc_args.z] = buff[struc_args.i];
            struc_args.z++;
            struc_args.i++;
        }
    }
    st->array[struc_args.j][struc_args.z] = '\0';
    st->array[nbr] = NULL;
    st->new_dir = nbr;
}
