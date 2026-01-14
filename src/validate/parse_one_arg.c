/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_one_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:35:10 by rcamps-v          #+#    #+#             */
/*   Updated: 2026/01/14 12:29:26 by rcamps-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parse_one_arg(char *args, int *size)
{
	int		len;
	int		*nums_array;
	char	**matrix;

	if (!args)
		free_and_exit(1, NULL, 0);
	matrix = ft_split(args, ' ');
	if (!matrix)
		free_and_exit(1, NULL, 0);
	len = 0;
	while (matrix[len])
		len++;
	nums_array = malloc(len * sizeof(int));
	if (!nums_array)
		free_and_exit(1, NULL, 0);
	nums_array = ft_atol_and_validation(matrix);
	free(matrix);
	return (*size = len, nums_array);
}
