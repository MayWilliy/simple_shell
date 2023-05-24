#ifndef _SHELL_H_
#define _SHELL_H_

/*header files*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/*constants for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/*used by a function called convert_number() */
#define CONVERT_LOWERCASE       1
#define CONVERT_UNSIGNED        2

/*constants used for command chaining */
#define CMD_NORM        0
#define CMD_OR          1
#define CMD_AND         2
#define CMD_CHAIN       3

/*constants to determine getline() or strtok() for input  */
#define USE_GETLINE 0
#define USE_STRTOK 0

/*constants to set name and size of history file*/
#define HIST_FILE       ".simple_shell_history"
#define HIST_MAX        4096

/*global environmental variable*/
extern char **environ;

/**
 * struct liststr - defines a singly linked list
 * @num: the number field
 * @str: a string
 * @next: This points to the next node
 */
typedef struct liststr
{
        int num;
        char *str;
        struct liststr *next;
} list_t;

/**
 * struct passinfo - This contains pseudo-arguements to pass into a function,
 * allowing uniform prototype for function pointer struct
 * @arg: A string generated from getline containing arguements
 * @argv:An array of strings generated from arg
 * @path: A string path for the current command
 * @argc: The argument count
 * @line_count: The error count
 * @err_num: The error code for exit()s
 * @linecount_flag: if on count this line of input
 * @fname: The program filename
 * @env: linked list local copy of environ
 * @environ: A custom modified copy of environ from LL env
 * @history: The history node
 * @alias: The alias node
 * @env_changed: on if environ was changed
 * @status: The return status of the last exec'd command
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: The fd from which to read line input
 * @histcount: The history line number count
 */

typedef struct passinfo
{
        char *arg;
        char **argv;
        char *path;
        int argc;
        unsigned int line_count;
        int err_num;
        int linecount_flag;
        char *fname;
        list_t *env;
        list_t *history;
        list_t *alias;
        char **environ;
        int env_changed;
        int status;

        char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
        int cmd_buf_type; /* CMD_type ||, &&, ; */
        int readfd;
        int histcount;
} info_t;

/*A Macro that initializes an instance of info_t with default values*/
#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
                0, 0, 0}

/**
 * struct builtin - This contains a builtin string and related function
 * @type: The builtin command flag
 * @func: The function
 */
typedef struct builtin
{
        char *type;
        int (*func)(info_t *);
} builtin_table;

/* function prototypes for functions used in the program */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);
void shell_interactive(void);
void shell_no_interactive(void);
int main(void);
int arguments(int argc, char *argv[]);
int handle_path(char *PATH);
int exit_shell(void);
int environ(char **environ);

/* setenv_and_unsetetenv.c */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);
