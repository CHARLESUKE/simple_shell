#ifndef _MAIN_H_
#define _MAIN_H_

#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>


#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;

/**
 * struct liststring - this function is the singly linked list
 * @num: this function is the the number field
 * @str: this function is the a string
 * @nxt: this function is the points to the next node
 */
typedef struct list_str
{
	int num;
	char *str;
	struct list_str *next;
} list_s;
/**
 * struct cmd_dat - this function is the linked list created
 * @arg: this function is the pointer to strings with arguments
 * @argv: this function is the pointer to an array of strings
 * @path: this function is the string path
 * @argc: this fumction is the argument count (command-line arguments)
 * @line_count: this function is the characters count in a string
 * @err_num: this function is the error code
 * @linecount_flag: this function is the flag to count line of string inputs
 * @fname: this function is the pointer to program file
 * @readfd: this function is the file descriptor used for reading inputs
 * @env: this function is the linked list of environ variables
 * @environ: this function is the array of environ variables
 * @env_changed: this function is the checks for if environment has changed
 * @history: this function is the pointer to past entry
 * @histcount: this function is the memory for prev command entered
 * @status: this function is the result from prev command
 * @alias: this function is the command aliases
 * @cmd_buf: this function is the pointer address to command buffer
 * @cmd_buf_type: this function is the command buffer (CMD_type: || 0r &&, )
 */
typedef struct cmddata
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_s *env;
	list_s *history;
	list_s *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type; /* accepts and allows all ||, &&, ; */
	int readfd;
	int histcount;
} cmd_d;

#define CMDDATA_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct builtin - this function is builtin string 
 * @type: this variable is the builtin command flag
 * @func: this is the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(cmd_d *);
} builtin_list;


/* stringfunction(s) */
int _putchar(char);
void append_S(char *stringfield); /*conjoin strings from the personality*/
size_t string_length(char *stringfield);
int my_str_comp(const char *, const char *);
int replace_str(char **p, char *m);
char *str_concat(char *adr, char *ssrc);
char *my_str_copy(char *stringfield, char *source);
char *str_duplicate(const char *stringfield);
char *_check(const char *strsearch, const char *substrfin);


/*fork function(s)*/
void fork_c(cmd_d *command_dat);

/* simple shell loop functions */
int shell(cmd_d *, char **);
int find_builtIn(cmd_d *);
void path_cmd(cmd_d *);

/* resolve functions */
int if_exec_cmd(cmd_d *, char *);
char *char_dup(char *, int, int);
char *find_full_path(cmd_d *, char *, char *);


/* faults functions */
void append_err_s(char *);
int err_putchar(char);
int fd_putc(char e, int fd);
int fd_puts(char *stringtoconv, int fd);
int err_atoi(char *t);
void print_err(command_d *, char *);
int print_decimal(int entering, int file_d);
char *convert_num(long int numeral, int support, int myflags);
void rm_comments(char *buffer);


/* exit functions */
char *string_char(char *prompt, char t);
char *string_copy(char *destination, char *source, int m); /*Still in progress*/
char *string_concat(char *destination, char *source, int m);

/* free function(s) */
int _free_ptr(void **);

/* interactive shell function(s) */
int interactive_shell(cmd_d *);

/* atoi functions */
int _atoi(char *str);
int alpha_is(int c);
int is_delimeter(char c, char *d);

/* aka function(s) */
int alias_set(cmd_d *, char *str);
int alias_unset(cmd_d *, char *str);
int print_a(list_s *_node);
int cmd_alias(cmd_d *);

/* token function(s) */
char **token(char *str, char *delim);

/* built_command function */
int exit_cmd(cmd_d *);
int history_cmd(cmd_d *);
int help_cmd(cmd_d *);
int cd_cmd(cmd_d *);

/* the memory reallocation functions (reallocation) */
char *memory_set(char *, char, unsigned int);
void str_free(char **);
void *my_realloc(void *, unsigned int, unsigned int);


/* environ functions */
char **get_env(cmd_d *);
int set_env(cmd_d *, char *, char *); /* still confusing */
int unset_env(cmd_d *, char *);

/* surround functions */
char *_get_env(cmd_d *, const char *);
int my_env(cmd_d *);
int set_environ(cmd_d *);
int unset_environ(cmd_d *);
int populate_env(cmd_d *);

/* record functions */
char *history_file(cmd_d *);
int rd_history(cmd_d *);
int write_history(cmd_d *);
int build_history(cmd_d *, char *buffon, int line_count);
int number_history(cmd_d *);


/* getline_ functions (the getline functions) */
int my_getline(cmd_d *, char **, size_t *);
ssize_t input_buffer(cmd_d *, char **buffon, size_t *);
ssize_t read_buf(cmd_d *, char *buffon, size_t *);
ssize_t _input(cmd_d *);
void signalHandler(int);

/* command_data functions */
void set_cmd(cmd_d *, char **avv);
void clear_cmd(cmd_d *);
void free_cmd(cmd_d *, int u);

/* joined list functions */
list_s *add_node(list_s **, const char *, int);
list_s *add_to_list(list_s **, const char *, int);
size_t print_list_string(const list_s *);
int delete_node(list_s **, unsigned int);
void free_list(list_s **);
size_t list_length(const list_s *);
char **list_to_str(list_s *);
size_t prints_element(const list_s *);
list_s *start_node(list_s *, char *, char e);
ssize_t node_index(list_s *, list_s *);

/* variables functions */
int is_Chain(cmd_d *, char *buffer, size_t *prompt);
void chain_check(cmd_d *, char *, size_t *, size_t, size_t);
int replace_alias(cmd_d *);
int var_replace(cmd_d *);


#endif
