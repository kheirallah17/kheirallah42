
#include "pipex.h"

void	exec_cmd(char *cmd, char **envp)
{
	char	*env_path;
	char	**split_path;
	char	**cmd_args;
	char	*cmd_path;

	env_path = get_env(envp);
	if (!env_path)
		exit(127);
	split_path = ft_split(env_path, ':');
	cmd_args = ft_split(cmd, ' ');
	cmd_path = get_cmd_path(split_path, cmd_args[0]);
	if (!cmd_path)
	{
		free_split(split_path);
		free_split(cmd_args);
		write(2, "command not found\n", 18);
		exit(127);
	}
	free_split(split_path);
	execve(cmd_path, cmd_args, envp);
	free(cmd_path);
	free_split(cmd_args);
	perror("execve");
	exit(1);
}

static void	child1(int *pipefd, char **argv, char **envp)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_exit(argv[1], 1);
	dup2(fd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close_fds(fd, pipefd[1], pipefd);
	exec_cmd(argv[2], envp);
}

static void	child2(int *pipefd, char **argv, char **envp)
{
	int		fd;

	fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		error_exit(argv[4], 1);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close_fds(pipefd[0], fd, pipefd);
	exec_cmd(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	id1;
	pid_t	id2;
	int		status;

	if (argc != 5)
	{
		write(1, "Error: Invalid number of arguments\n", 36);
		return (1);
	}
	if (pipe(pipefd) == -1)
		return (perror("pipe"), 1);
	id1 = fork();
	if (id1 == 0)
		child1(pipefd, argv, envp);
	id2 = fork();
	if (id2 == 0)
		child2(pipefd, argv, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(id1, NULL, 0);
	waitpid(id2, &status, 0);
	return (WEXITSTATUS(status));
}
