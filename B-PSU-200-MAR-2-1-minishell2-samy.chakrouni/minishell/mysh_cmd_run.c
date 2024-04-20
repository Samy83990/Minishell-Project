/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-minishell2-samy.chakrouni
** File description:
** run_shell
*/

#include <stdlib.h>
#include <fcntl.h>
#include "my.h"

void run_shell1(get_sh_t *sh, int i)
{
    if (i == 0)
        my_cd(sh);
    if (i == 1)
        my_env(sh);
    if (i == 2)
        my_setenv(sh);
    if (i == 3)
        my_unsetenv(sh);
}

char **run_shell2(char **commands)
{
    commands[0] = "cd\0";
    commands[1] = "env\0";
    commands[2] = "setenv\0";
    commands[3] = "unsetenv\0";
    commands[4] = "exit\0";
    commands[5] = NULL;
    return (commands);
}

void run_shell(get_sh_t *sh)
{
    char **commands = malloc(sizeof(char *) * 6);
    int i = 0;

    commands = run_shell2(commands);
    while (i != 5) {
        if (my_strcmp(sh->array[0], commands[i]))
            break;
        else
            i++;
    }
    free(commands);
    if (i == 5) {
        if (exec_bin(sh))
            return;
        if (exec_prog(sh))
            return;
    }
    run_shell1(sh, i);
    return;
}