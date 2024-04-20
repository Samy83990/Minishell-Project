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

// Function to execute the command and redirect output
void execute_command_with_redirection(char* command, char* file) {
    // Redirect stdout to file
    freopen(file, "w", stdout);

    // Execute the command
    system(command);

    // Reset stdout to original
    freopen("/dev/tty", "w", stdout);
}

int main() {
    char input[1024];

    // Get the command line input
    printf("Enter your command: ");
    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = '\0'; // Remove newline character

    // Check if '>' is in the command
    char *redirect = strstr(input, ">");
    if (redirect) {
        *redirect = '\0'; // Split the input at '>'
        char *file = redirect + 1;
        while (*file == ' ') file++; // Skip spaces to get filename

        execute_command_with_redirection(input, file);
    } else {
        // Normal command execution
        system(input);
    }

    return 0;
}