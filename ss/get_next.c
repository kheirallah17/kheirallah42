#include "solong.h"

ssize_t	read_buffer(int fd, int *pos,
			int *buffers, char *buffer)
{
	*buffers = read(fd, buffer, BUFFER_SIZE);
	*pos = 0;
	return (*buffers);
}

char	*addline(int llength, char c, char *new_line)
{
	char	*new;
	int		k;

	k = 0;
	new = (char *)malloc(llength + 2);
	if (!new)
		return (NULL);
	while (k < llength)
	{
		new[k] = new_line[k];
		k++;
	}
	new[llength] = c;
	new[llength + 1] = '\0';
	free (new_line);
	return (new);
}

char	*read_line(int fd, int *pos, int *buffers, char *buffer)
{
	int		llength;
	char	*new_line;
	char	c;

	llength = 0;
	new_line = NULL;
	while (1)
	{
		if (*pos >= *buffers)
		{
			if ((read_buffer_function(fd, pos,
						buffers, buffer)) <= 0)
			{
				if (llength > 0)
					return (new_line);
				free (new_line);
				return (NULL);
			}
		}
		c = buffer[(*pos)++];
		new_line = addline(llength++, c, new_line);
		if (!new_line || c == '\n')
			break ;
	}
	return (new_line);
}

char	*get_next(int fd)
{
	static char	readbuffer[BUFFER_SIZE];
	static int	position = 0;
	static int	buffer_size = 0;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	return (read_line(fd, &position, &buffer_size, readbuffer));
}