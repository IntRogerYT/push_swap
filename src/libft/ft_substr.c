/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <rcamps-v@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:15:01 by rcamps-v          #+#    #+#             */
/*   Updated: 2026/01/07 11:16:55 by rcamps-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*startstr;
	char	*substr;
	size_t	i;

	if (!s)
		return (ft_strdup(""));
	if (start > ft_strlen(s) || *s == '\0')
		return (ft_strdup(""));
	startstr = (char *)(s + start);
	if (len > ft_strlen(startstr))
		substr = malloc(ft_strlen(startstr) + 1);
	else
		substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && startstr[i] != '\0')
	{
		substr[i] = startstr[i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
