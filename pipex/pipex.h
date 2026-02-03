
#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include "libft/libft.h"

char	*get_env(char **envp);
char	*get_cmd_path(char **split_path, char *cmd);
void	free_split(char **split);
void	error_exit(char *msg, int code);
void	close_fds(int fd1, int fd2, int *pipefd);

#endif