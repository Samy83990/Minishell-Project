/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-minishell2-samy.chakrouni
** File description:
** mysh_line
*/

#include <stdlib.h>
#include "my.h"
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

void check_semi(get_sh_t *sh)
{
    for (int i = 0; sh->buff[i] != '\0'; i++)
        if (sh->buff[i] == ';')
            sh->m = 1;
}

void free_args(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}

void check_line(get_sh_t *sh)
{
    sh->m = 0;
    sh->new_dir = 0;
    sh->k = 0;
    sh->buff = supprime_1(sh->buff);
    check_semi(sh);
    if (sh->m == 0) {
        if (my_strcmp(sh->buff, "exit"))
            exit(0);
        get_args(sh, sh->buff);
        run_shell(sh);
        free_args(sh->array);
    }
    if (sh->m == 1) {
        for (int k = 0; k != sh->k; k++) {
            get_args(sh, sh->i[k]);
            run_shell(sh);
            free_args(sh->array);
        }
    }
}

