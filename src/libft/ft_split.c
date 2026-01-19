/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <rcamps-v@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:14:43 by rcamps-v          #+#    #+#             */
/*   Updated: 2026/01/19 15:18:13 by rcamps-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_words_count(char const *s, char c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	if (*s == '\0')
		return (0);
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
			count++;
		i++;
	}
	if (s[i - 1] == c)
		return (count);
	return (count + 1);
}

void	ft_free(char **matrix, size_t aux)
{
	size_t	i;

	i = 0;
	while (i < aux)
		free(matrix[i++]);
	free(matrix);
}

size_t	ft_startpos(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char	**ft_split_words(char **matrix, char const *s, char c, size_t words)
{
	size_t	len;
	size_t	start;
	size_t	i;

	i = 0;
	start = 0;
	while (i < words)
	{
		while (s[start] == c)
			start++;
		len = ft_startpos((s + start), c);
		matrix[i] = ft_substr(s, start, len);
		if (!matrix[i])
		{
			ft_free(matrix, i);
			return (NULL);
		}
		start += len + 1;
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

char	**ft_split(char *s, char c)
{
	char	**matrix;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_words_count(s, c);
	matrix = malloc((ft_words_count(s, c) + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	if (words == 1)
	{
		matrix[0] = ft_strdup(s);
		matrix[1] = NULL;
		return (matrix);
	}
	if (ft_split_words(matrix, s, c, words) == NULL)
		return (NULL);
	return (matrix);
}
