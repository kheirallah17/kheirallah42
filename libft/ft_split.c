/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-mawl <kal-mawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:50:55 by khairallahm       #+#    #+#             */
/*   Updated: 2025/05/29 07:58:33 by kal-mawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *s, char c)
{
	size_t	i;
	int		counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c)
			|| (i > 0 && (s[i - 1] == c && s[i] != c)))
			counter++;
		i++;
	}
	return (counter);
}

static char	*length_strdup(const char *s, size_t start, size_t end)
{
	size_t	i;
	char	*newarray;
	size_t	length;

	i = 0;
	length = end - start + 1;
	newarray = (char *)malloc((length + 1) * sizeof(char));
	if (!newarray)
		return (NULL);
	newarray[length] = '\0';
	while (i < length)
	{
		newarray[i] = s[start];
		start++;
		i++;
	}
	return (newarray);
}

static void	freearray(char **array, size_t index)
{
	while (index > 0)
	{
		free(array[index]);
		index--;
	}
	free(array);
}

char	**populate(char **arrayofstrings, const char *s, char c, int length)
{
	size_t	end;
	size_t	start;
	int		index;

	start = 0;
	end = 0;
	index = 0;
	while (s[end] && index < length)
	{
		if ((end == 0 && s[end] != c)
			|| (end > 0 && s[end - 1] == c && s[end] != c))
			start = end;
		if (s[end] != c && (!s[end + 1] || s[end + 1] == c))
		{
			arrayofstrings[index] = length_strdup(s, start, end);
			if (!arrayofstrings[index])
			{
				freearray(arrayofstrings, index);
				return (NULL);
			}
			index++;
		}
		end++;
	}
	return (arrayofstrings);
}

char	**ft_split(const char *s, char c)
{
	char	**arrayofstrings;
	int		length;

	if (!s)
		return (NULL);
	length = count_word(s, c);
	arrayofstrings = (char **)malloc((length + 1) * sizeof(char *));
	if (!arrayofstrings)
		return (NULL);
	arrayofstrings[length] = NULL;
	populate(arrayofstrings, s, c, length);
	return (arrayofstrings);
}

/*
void main(void) {
	char **arr = ft_split("a b c", ' ');
	for (int i = 0; arr[i]; i++) {
		printf("[%s]\n", arr[i]);
		free(arr[i]);
	}
	free(arr);
}
*/