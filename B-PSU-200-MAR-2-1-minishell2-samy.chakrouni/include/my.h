/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-minishell2-samy.chakrouni
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #define MAX_ENV_SIZE 1000

    #include <sys/types.h>
    #include <sys/wait.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <sys/stat.h>

typedef struct my {
    char **env;
    char *buff;
    char **i;
    char **array;
    int new_dir;
    int m;
    int k;
    char *tok;
    char *output_file;
} get_sh_t;

typedef struct my2 {
    int i;
    int j;
    int z;
} ar_t;

void copy_env(get_sh_t *sh, char **envp);
void minishell(get_sh_t *sh);
char *check_buff(char *buff);
void get_args(get_sh_t *sh, char *buff);
int check_if_dir(get_sh_t *sh);
char *supprime_buf(char *buf);
int redirection_func(get_sh_t *st);
void check_line(get_sh_t *sh);
int count_args(char *buff, char sep);
char *supprime_1(char *buff);
void run_shell(get_sh_t *sh);
char *my_strdup(char const *src);
void parse_redirection(get_sh_t *st);
void my_env(get_sh_t *sh);
void my_setenv(get_sh_t *sh);
void my_unsetenv(get_sh_t *sh);
void my_cd(get_sh_t *sh);
int exec_bin(get_sh_t *sh);
char **chemin_1(char **env, char const *var);
int exec_prog(get_sh_t *sh);
void my_putchar(char c);
void free_env(get_sh_t *st);
char *my_strcpy(char *dest, char const *src);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *str1, char const *str2);
char *my_strcat(char *dest, char const *src);
int my_strncmp(const char *str1, const char *str2, size_t n);
void run_shell3(get_sh_t *st);
char **separate_paths(char *path);
void free_args(char **array);
void delim(get_sh_t *st);

#endif
