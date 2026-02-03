#include "pipex.h"

char	*get_env(char **envp)
{
	while (*envp)
	{
		if (strncmp(*envp, "PATH=", 5) == 0)
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

char	*get_cmd_path(char **split_path, char *cmd)
{
	int		i;
	char	*cmd_path;
	char	*tmp;

	if (!split_path || !cmd)
		return (NULL);
	i = 0;
	while (split_path[i])
	{
		tmp = ft_strjoin(split_path[i], "/");
		if (!tmp)
			return (NULL);
		cmd_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!cmd_path)
			return (NULL);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

void	free_split(char **split)
{
	int	i;
	if (!split)
		return;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	error_exit(char *msg, int code)
{
	if(msg)
		perror(msg);
	exit(code);
}

void	close_fds(int fd1, int fd2, int *pipefd)
{
	if (fd1 >= 0)
		close(fd1);
	if (fd2 >= 0)
		close(fd2);
	close(pipefd[0]);
	close(pipefd[1]);
}