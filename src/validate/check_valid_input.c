/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <rcamps-v@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:54:38 by rcamps-v          #+#    #+#             */
/*   Updated: 2026/01/07 11:48:26 by rcamps-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*validate_and_parse(int argc, char **argv, int *size)
{
	int		i;
	int		len;
	int		*nums_array;
	char	**matrix;

	matrix = remove_first_arg(argc, argv);
	len = 0;
	while (matrix[len])
		len++;
	nums_array = malloc((len + 1) * sizeof(int));
	i = 0;
	while (matrix[i])
	{
		nums_array[i] = ft_atoi(matrix[i]);
		if (!nums_array[i])
			return (0);
		i++;
	}
	return (nums_array);
}
