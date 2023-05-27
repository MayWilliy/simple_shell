#include "shell.h"
#define MAX_COMMAND_LENGTH 100

/* * fork - fork a new process
 * Return: 0
 */
void execute_command(char *command)
{
	char *argv[] = {NULL};
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
		/*handle_path(char *PATH);*/
		/* Handle arguments */
		execve(command, argv, NULL);
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

