/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:03:21 by rcamps-v          #+#    #+#             */
/*   Updated: 2026/01/14 14:25:30 by rcamps-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_exit(int code_error, char **matrix, long *nums_array)
{
	if (matrix)
		free(matrix);
	if (nums_array)
		free(nums_array);
	write(2, "Error\n", 6);
	exit(code_error);
}

void	free_stacks(int code_error, t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp;

	if (stack_a)
	{
		temp = stack_a;
		stack_a = stack_a->next;
		free(temp);
	}
	if (stack_b)
	{
		temp = stack_b;
		stack_b = stack_b->next;
		free(temp);
	}
	write(2, "Error\n", 6);
	exit(code_error);
}
