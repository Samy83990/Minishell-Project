/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-minishell2-samy.chakrouni
** File description:
** mysh
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include <string.h>

void my_env(get_sh_t *st)
{
    for (int i = 0; st->env[i] != NULL; i++) {
        my_putstr(st->env[i]);
        my_putchar('\n');
    }
}

void copy_env(get_sh_t *sh, char **envp)
{
    int i = 0;

    while (envp[i] != NULL)
        i++;
    sh->env = malloc(sizeof(char *) * (i + 1));
    if (sh->env == NULL)
        exit(1);
    for (int j = 0; j < i; j++) {
        sh->env[j] = my_strdup(envp[j]);
        if (sh->env[j] == NULL)
            exit(1);
    }
    sh->env[i] = NULL;
}

void run_shell3(get_sh_t *st)
{
    size_t size = 0;

    my_putstr("<$ ");
    if (getline(&st->buff, &size, stdin) == EOF) {
        free(st->buff);
        return;
    }
    check_line(st);
    run_shell3(st);
}

void free_env(get_sh_t *st)
{
    for (int i = 0; st->env[i] != NULL; i++)
        free(st->env[i]);
    free(st->env);
    free(st);
}

int main(int argc, char **argv, char **envp)
{
    get_sh_t *st = malloc(sizeof(get_sh_t));

    if (argc != 1 || argv[0] == NULL)
        return 84;
    copy_env(st, envp);
    run_shell3(st);
    free_env(st);
    return 0;
}
