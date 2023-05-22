#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/* Including Standard libraries */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

/* Definin Macros */
#define PRINTER(c) (write(STDOUT_FILENO, c, _strlen(c)))
#define DELIM " \t\r\n\a"
#define BUFSIZE 1024

/* Environment variable Macro */
extern char **environ;

/**
 * struct bulltin - contain bultin to handle and function to excute
 * @command:pointer to char
 * @func:fun to excute when bultin true
 */
typedef struct bulltin
{
	char *command;
	int (*func)(char **line, int er);
} builtin_t;

/* String functions prototypes */
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);
char *_strtok(char *str, const char *tok);
unsigned int check_delimiter(char c, const char *str);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _putchar(char c);
int int_length(int num);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void array_rev(char *arr, int len);

/* Memory Handling functions protytypes */
void *_calloc(unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memcpy(char *dest, char *src, unsigned int n);
void free_all(char **input, char *line);
void free_env(char **env);
void *fill_an_array(void *a, int el, unsigned int len);

/* Display functions protytypes */
void signal_to_handel(int sig);
void display_prompt(void);
char *_getline(void);

/* Parsing User commands functions protytypes */
int check_bltn(char **cmd);
void create_env_array(char **envi);
int command_path(char **line);
char *_getenv(char *name);
char *build(char *token, char *value);
int check_cmd(char **tokens, char *line, int count, char **argv);
void treat_file(char *line, int counter, FILE *fd, char **argv);
char **parse_command(char *cmd);
int handle_builtin(char **cmd, int er);
void read_file(char *filename, char **argv);
void exit_file(char **cmd, char *line, FILE *fd);

/* Helper functions protytypes */
void hash_handler(char *buff);
int echo_bul(char **cmd, int er);
void exit_status_shell(char **cmd, char *input, char **argv, int c);
int disp_hist(char **cmd, int er);
int history(char *input);
int display_help(char **cmd, int er);
int dis_env(char **cmd, int er);
int change_dir(char **cmd, int er);
int print_ech(char **cmd);

/* Error handling function protytypes*/
void print_err(char *line, int c, char **argv);
void print_num(unsigned int n);
void print_num_pch(int n);
void _prerror(char **argv, int c, char **cmd);

#endif /* SIMPLE_SHELL_H */
