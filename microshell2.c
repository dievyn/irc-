#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int cd (char *arg)
{
	printf("%s\n", arg);
	return (1);
}

void print_tab(char **tab)
{
	int i = 0;

	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

int main (int argc, char **argv, char **envp)
{
	int i = 1;
	int j = 0;
	int pid;
	int status;
	int fd;
	int pipe_state;
	int pi[2];
	char **arguments;

	while (j < argc)
	{
		if (argv[j][0] == '|')
			pipe_state = 1;
		else
			pipe_state = 0;
		j++;
		if (strcmp(argv[j], "cd\0") == 0)
		{
			j++;
			j = cd(argv[j]);
		}
		else
		{
			while (argv[i] && strcmp(argv[i], ";\0") != 0 && strcmp(argv[i], "|\0") != 0)
				i++;
			arguments = malloc((i + 1) * sizeof (char *));
			i = 0;
			while (argv[j] && strcmp(argv[j], ";\0") != 0 && strcmp(argv[j], "|\0") != 0)
			{
				arguments[i] = argv[j];
				j++;
				i++;
			}
			i = j + 1;
			if (argv[j] && strcmp(argv[j], "|\0") == 0)
				pipe(pi);
			printf ("%d\n%d\n-=-=-\n", pi[0], pi[1]);
			pid = fork();
			if (pid == 0)
			{
				if (argv[j] && strcmp(argv[j], "|\0") == 0)
					dup2(pi[1], 1);
				if (pipe_state == 1)
					dup2(fd, 0);
				close (pi[0]);
				close (pi[1]);
				close (fd);
				if (execve(arguments[0], arguments, envp) == -1)
					return (printf("Fatal error.\n"));
			}
			else
				waitpid(pid, &status, 0);
			fd = pi[0];
			close (pi[1]);
			if (!argv[j] || strcmp(argv[j], "|\0") != 0)
				close (pi[0]);
			free(arguments);
		}
	}
	close (pi[0]);
	close (pi[1]);
}

//	./a.out /usr/bin/ls "|" /usr/bin/grep c "|" /usr/bin/grep i

//	valgrind --trace-children=yes --track-fds=yes ./a.out /usr/bin/ls "|" /usr/bin/grep c "|" /usr/bin/grep i

//	./a.out /usr/bin/ls "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|"