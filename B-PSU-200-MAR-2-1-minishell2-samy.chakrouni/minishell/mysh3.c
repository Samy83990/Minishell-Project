/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-minishell2-samy.chakrouni
** File description:
** mysh3
*/

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include "my.h"

int is_in_str(char *str, char *str2)
{
    int len_str = my_strlen(str);
    int len_str2 = my_strlen(str2);

    if (len_str > len_str2)
        return 0;
    for (int i = 0; i < len_str; i++) {
        if (str[i] != str2[i])
            return 0;
    }
    return 84;
}

char *my_getenv(char *str, char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (is_in_str(str, env[i]) == 1)
            return env[i];
    }
    return NULL;
}

void my_cd(get_sh_t *st)
{
    const char *home;

    if (st->new_dir == 1) {
        home = my_getenv("HOME", st->env);
        if (home != NULL)
            chdir(home);
        return;
    }
    if (st->new_dir > 2)
        return;
    chdir(st->array[1]);
}
