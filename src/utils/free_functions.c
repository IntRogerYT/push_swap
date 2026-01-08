/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:03:21 by rcamps-v          #+#    #+#             */
/*   Updated: 2026/01/08 14:34:52 by rcamps-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_exit(int code_error, char **matrix, long *nums_array)
{
	if (matrix)
		free(matrix);
	if (nums_array)
		free(nums_array);
	exit(code_error);
}
