/*include guards*/
#ifndef _SHELL_H_
#define _SHELL_H_
#endif
#ifndef __ENVIRON
#define __ENVIRON
#endif
extern char **environ;

/*Required Header files*/
#ifndef _HEADER
#define _HEADER
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#endif
#ifndef _FUNC_PROTS
#define _FUNC_PROTS
int exec(int count, char *arrayv[]);

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

/*Constants for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/*The constants used by a function called convert_number() */
#define CONVERT_LOWERCASE       1
#define CONVERT_UNSIGNED        2

/*The constants used for command chaining */
#define CMD_NORM        0
#define CMD_OR          1
#define CMD_AND         2
#define CMD_CHAIN       3

/*The constants used to used determine getline() or strtok() for input  */
#define USE_GETLINE 0
#define USE_STRTOK 0

/*The constants used to set name and size of history file*/
#define HIST_FILE       ".simple_shell_history"
#define HIST_MAX        4096

/*The global environmental variable prototype*/
extern char **environ;

/**
 * struct liststr - This defines a singly linked list
 * @num: The number field
 * @str: a string
 * @next: This points to the next node
 */

typedef struct liststr /*struct prototype*/
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

	char **cmd_buf; /* Pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

/*A Macro that initializes an instance of info_t with default values*/
#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct builtin - This contains a builtin string and a related function
 * @type: The builtin command flag
 * @func: The function
 *@info_t:interger pointer
 */
typedef struct builtin
{
	char *type;
	int *info_t;

} builtin_table;

/* The function prototypes for functions used in the program */
int main(void);
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);
void shell_interactive(void);
void shell_no_interactive(void);
int handle_path(char *PATH);
int exit_shell(void);

/* setenv_and_unsetetenv.c */
char **get_environ(info_t *);
int populate_env_list(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/*string prototype */
char *_strncpy(char *dest, char *src, int n);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/*string prototype*/
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/*list prototype*/
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/*node prototype */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);


/*history prototype*/
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

#endif
