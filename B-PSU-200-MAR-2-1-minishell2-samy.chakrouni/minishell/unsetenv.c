/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-minishell2-samy.chakrouni
** File description:
** my_unsetenv
*/

#include <stdlib.h>
#include "my.h"
#include <string.h>

void supp_2(char **env, int index)
{
    free(env[index]);
    for (int i = index; env[i] != NULL; i++)
        env[i] = env[i + 1];
}

void supp_val(get_sh_t *st, const char *arg)
{
    for (int i = 0; st->env[i] != NULL; i++) {
        if (my_strncmp(st->env[i], arg, my_strlen(arg))
            == 0 && st->env[i][my_strlen(arg)] == '=') {
            supp_2(st->env, i);
            break;
        }
    }
}

void my_unsetenv(get_sh_t *st)
{
    if (st->new_dir == 1)
        return;
    for (int j = 1; j < st->new_dir; j++)
        supp_val(st, st->array[j]);
}
