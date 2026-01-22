/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_one_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:35:10 by rcamps-v          #+#    #+#             */
/*   Updated: 2026/01/22 13:04:42 by rcamps-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	nums_validation_args(long *nums_array, int len, char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		if (nums_array[i] < INT_MIN || nums_array[i] > INT_MAX)
		{
			freem_and_exit(matrix, nums_array);
		}
		j = i + 1;
		while (j < len)
		{
			if (nums_array[i] == nums_array[j])
			{
				freem_and_exit(matrix, nums_array);
			}
			j++;
		}
		i++;
	}
}

int	*ft_atol_and_validation_args(char **matrix)
{
	long	*temp;
	int		*nums_array;
	int		len;
	int		i;

	len = num_args(matrix);
	temp = malloc((len + 1) * sizeof(long));
	if (!temp)
		freem_and_exit(matrix, 0);
	i = -1;
	while (matrix[++i])
	{
		if (ft_is_number(matrix[i]) == 1 || matrix[i][0] == '\0')
			freem_and_exit(matrix, temp);
		temp[i] = ft_atol(matrix[i]);
	}
	nums_validation_args(temp, len, matrix);
	nums_array = malloc(len * sizeof(int));
	if (!nums_array)
		freem_and_exit(matrix, temp);
	i = -1;
	while (++i < len)
		nums_array[i] = (int)temp[i];
	return (free(temp), nums_array);
}

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
	{
		if (ft_is_number(matrix[len]) == 1)
		{
			free_matrix(matrix);
			write(2, "Error\n", 6);
			exit(1);
		}
		len++;
	}
	nums_array = ft_atol_and_validation_args(matrix);
	free_matrix(matrix);
	return (*size = len, nums_array);
}
