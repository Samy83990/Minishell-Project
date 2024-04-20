/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-minishell2-samy.chakrouni
** File description:
** exec_prog
*/

#include "my.h"
#include <fcntl.h>
#include <stdio.h>

int chemin_2(char *arg, char **env)
{
    char **path = chemin_1(env, "PATH");

    if (path == NULL)
        return 84;
    for (int i = 0; path[i] != NULL; i++)
        if (my_strcmp(path[i], arg))
            return 0;
    return 84;
}

char *get_name(char *arg)
{
    char *name = malloc(sizeof(char) * (my_strlen(arg) + 1));
    int i = 0;
    int j = 2;

    while (arg[j] != '\0') {
        name[i] = arg[j];
        i++;
        j++;
    }
    return name;
}

int check_if_dir(get_sh_t *sh)
{
    char *name = get_name(sh->array[0]);
    struct stat st;

    if (sh->array[0][0] != '.') {
        if (S_ISDIR(st.st_mode) || chemin_2(sh->array[0], sh->env))
            return 0;
        return 84;
    }
    free(name);
    return 84;
}

int exec_prog(get_sh_t *sh)
{
    struct stat st;
    int pid = 0;
    int status = 0;
    int out_fd;

    if (check_if_dir(sh) == 0)
        return 84;
    if (access(sh->array[0], F_OK | X_OK) == -1)
        return 84;
    pid = fork();
    if (pid == -1)
        return 84;
    else if (pid == 0) {
        execve(sh->array[0], sh->array, sh->env);
        return 84;
    } else
        wait(&status);
    return 0;
}