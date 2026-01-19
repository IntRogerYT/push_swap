/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <rcamps-v@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:22:09 by rcamps-v          #+#    #+#             */
/*   Updated: 2026/01/19 12:31:55 by rcamps-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_number(const char *nptr)
{
	int	i;

	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[0] == '+' || nptr[0] == '-')
		i++;
	while (nptr[i])
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

long	ft_atol(const char *nptr)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	if (ft_is_number(nptr) == 1 || nptr[i] == '\0')
		return (LONG_MIN);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (num * 10 > LONG_MAX)
			return (LONG_MIN);
		num = num * 10 + nptr[i] - '0';
		i++;
	}
	return (num * sign);
}
