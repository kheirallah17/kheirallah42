/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-mawl <kal-mawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:53:57 by kal-mawl          #+#    #+#             */
/*   Updated: 2025/07/15 08:54:18 by kal-mawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	char_is_separator(char cc, char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		if (cc == c[i])
			return (1);
		i++;
	}
	if (cc == '\0')
		return (1);
	return (0);
}

void	write_word(char *dest, const char *from, char *charset)
{
	int	i;

	i = 0;
	while (char_is_separator(from[i], charset) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

static int	count_word(const char *s, char *c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (char_is_separator(s[i + 1], c) == 1
			&& char_is_separator(s[i], c) == 0)
			words++;
		i++;
	}
	return (words);
}

void	populate(char **arrayofstrings, const char *s, char *c)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (char_is_separator(s[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (char_is_separator(s[i + j], c) == 0)
				j++;
			arrayofstrings[word] = (char *)malloc(sizeof(char) * (j + 1));
			write_word(arrayofstrings[word], s + i, c);
			i += j;
			word++;
		}
	}
}

char	**ft_split(const char *s, char *c)
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
	populate(arrayofstrings, s, c);
	return (arrayofstrings);
}
