#include "shell.h"

/**
 * main - The main Entry point
 * @ac: argument count
 * @av: argument vector
 *
 * Return value:The code should return 0 on success, and 1 on error
 */
int argument(int ac, char **av)
{
        info_t info[] = { INFO_INIT };
        int fd = 2;

        asm ("mov %1, %0\n\t"
                        "add $3, %0"
                        : "=r" (fd)
                        : "r" (fd));

        if (ac == 2)
        {
                fd = open(av[1], O_RDONLY);
                if (fd == -1)
                {
                        if (errno == EACCES)
                                exit(126);
                        if (errno == ENOENT)
                        {
                                puts(av[0]);
                                puts(": 0: Can't open ");
                                puts(av[1]);
                                putchar('\n');
                                putchar(BUF_FLUSH);
                                exit(127);
                        }
                        return (EXIT_FAILURE);
                }
                info->readfd = fd;
        }
        populate_env_list(info);
        read_history(info);
        hsh(info, av);
        return (EXIT_SUCCESS);
}
