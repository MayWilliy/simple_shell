#include "shell.h"
#define MAX_COMMAND_LENGTH 100

/**
 * main - Entry point
 * prompt - Display a prompt and wait for the user to type a command
 * Return: Nothing cause it is void
 */
int main(void)
{
	int argv[MAX_COMMAND_LENGTH];
	char command[MAX_COMMAND_LENGTH];
	char *path = getenv("PATH");
	char *arguments[MAX_COMMAND_LENGTH];
		
	while (true)
	{
	if (isatty(STDIN_FILENO))
		printf(STDOUT_FILENO, "shell >", 7);
	fflush(stdout);
	if (getline(command, MAX_COMMAND_LENGTH, stdin))
	{
		break;
	}
	command[strcspn(command, "\n")] = '\0';
	/* Fork a new process */
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
	/* Child process */
	pid_t child_pid = getpid();
	pid_t parent_pid = getppid();

	printf("Child PID: %d\n", child_pid);
	printf("Parent PID: %d\n", parent_pid);
	/* Tokenize and concatenate the PATH */
	handle_path(path);
	/* Handle arguments */
	execve(command, argv[], NULL);
	perror("exec");
	exit(EXIT_FAILURE);
	}
	else
	{
	/* Parent process */
	int status;

	wait(&status);
	printf("Child process exited with status: %d\n", WEXITSTATUS(status));
	}
	}

	return (0);
}
