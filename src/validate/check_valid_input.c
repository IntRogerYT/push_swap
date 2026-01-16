/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <rcamps-v@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:54:38 by rcamps-v          #+#    #+#             */
/*   Updated: 2026/01/16 13:27:25 by rcamps-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	nums_validation(long *nums_array, int len)
{
	int	i;

	i = 0;
	while (i < len && nums_array[i])
	{
		if (nums_array[i] < INT_MIN || nums_array[i] > INT_MAX)
			free_and_exit(1, NULL, nums_array);
		i++;
	}
}

int	*ft_atol_and_validation(char **matrix)
{
	long	*temp;
	int		*nums_array;
	int		len;
	int		i;

	len = num_args(matrix);
	temp = malloc((len + 1) * sizeof(long));
	if (!temp)
		free_and_exit(1, matrix, 0);
	i = 0;
	while (matrix[i])
	{
		temp[i] = ft_atol(matrix[i]);
		i++;
	}
	temp[i] = 0;
	nums_validation(temp, len);
	nums_array = malloc(len * sizeof(int));
	if (!nums_array)
		free_and_exit(1, matrix, temp);
	i = -1;
	while (++i < len)
		nums_array[i] = (int)temp[i];
	return (free(temp), nums_array);
}

int	num_args(char **args)
{
	int		i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

char	**remove_first_arg(char **argv)
{
	char	**matrix;
	int		i;
	int		n_args;

	n_args = num_args(argv);
	matrix = malloc(n_args * sizeof(char *));
	if (!matrix)
		free_and_exit(1, NULL, 0);
	i = 1;
	while (argv[i])
	{
		matrix[i - 1] = argv[i];
		i++;
	}
	matrix[i - 1] = NULL;
	return (matrix);
}

int	*validate_and_parse(int argc, char **argv, int *size)
{
	int		len;
	int		*nums_array;
	char	**matrix;

	matrix = remove_first_arg(argv);
	len = 0;
	while (matrix[len])
		len++;
	nums_array = ft_atol_and_validation(matrix);
	free(matrix);
	return (*size = len, nums_array);
}
