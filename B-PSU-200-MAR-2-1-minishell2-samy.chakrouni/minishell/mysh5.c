/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-minishell2-samy.chakrouni
** File description:
** exec_bin
*/

#include "my.h"
#include <string.h>
#include <stdio.h>

char **chemin(char **path, char *command)
{
    for (int i = 0; path[i] != NULL; i++) {
        path[i] = my_strcat(path[i], "/");
        path[i] = my_strcat(path[i], command);
    }
    return path;
}

int exec_bin(get_sh_t *sh)
{
    char **path = chemin_1(sh->env, "PATH");
    int i = 0;
    int status = 0;

    if (path == NULL)
        return 84;
    path = chemin(path, sh->array[0]);
    for (i = 0; path[i] != NULL; i++)
        if (access(path[i], F_OK) != -1)
            break;
    if (path[i] == NULL)
        return 84;
    status = fork();
    if (status == 0) {
        execve(path[i], sh->array, sh->env);
        status = fork();
    }
    wait(&status);
    return 84;
}

char **chemin_1(char **env, const char *var)
{
    int i = 0;

    while (env[i] != NULL) {
        if (my_strncmp(env[i], var, my_strlen(var))
            == 0 && env[i][my_strlen(var)] == '=')
            return separate_paths(env[i] + strlen(var) + 1);
        i++;
    }
    return NULL;
}
