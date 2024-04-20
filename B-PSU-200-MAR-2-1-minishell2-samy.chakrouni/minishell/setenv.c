/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-minishell2-samy.chakrouni
** File description:
** setenv
*/

#include <stdlib.h>
#include "my.h"
#include <string.h>

int my_setenv2(const char *name)
{
    for (int i = 0; name[i] != '\0'; i++)
        if (!((name[i] >= 'A' && name[i] <= 'Z') ||
            (name[i] >= 'a' && name[i] <= 'z') || name[i] == '_'))
            return 0;
    return 84;
}

static void new_envir(get_sh_t *st, char *new_env)
{
    int env = 0;

    while (st->env[env] != NULL && env < MAX_ENV_SIZE)
        env++;
    if (env == MAX_ENV_SIZE) {
        free(new_env);
        return;
    }
    st->env[env] = new_env;
    st->env[env + 1] = NULL;
}

void update_existing_envir(get_sh_t *st, int i, char *new_env)
{
    free(st->env[i]);
    st->env[i] = new_env;
}

static char *create_new_env(get_sh_t *st)
{
    char *new_env = my_strcat(st->array[1], "=");

    if (st->array[2] != NULL)
        new_env = my_strcat(new_env, st->array[2]);
    return new_env;
}

static int find_envir(get_sh_t *st)
{
    int i = -1;

    for (int i = 0; st->env[i] != NULL; i++) {
        if (my_strncmp(st->env[i], st->array[1],
            my_strlen(st->array[1])) == 0) {
            i = i;
            break;
        }
    }
    return i;
}

void my_setenv(get_sh_t *st)
{
    char *new_env;
    int i;

    if (st->new_dir > 4 || st->array[1] == NULL || !my_setenv2(st->array[1]))
        return;
    i = find_envir(st);
    new_env = create_new_env(st);
    if (i != -1) {
        update_existing_envir(st, i, new_env);
    } else {
        new_envir(st, new_env);
    }
}
