/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:03:21 by rcamps-v          #+#    #+#             */
/*   Updated: 2026/01/17 14:26:25 by rcamps-v         ###   ########.fr       */
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

void	free_stacks(int code_error, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (stack_a && *stack_a)
	{
		while (*stack_a)
		{
			temp = *stack_a;
			*stack_a = (*stack_a)->next;
			free(temp);
		}
	}
	if (stack_b && *stack_b)
	{
		while (*stack_b)
		{
			temp = *stack_b;
			*stack_b = (*stack_b)->next;
			free(temp);
		}
	}
	write(2, "Error\n", 6);
	exit(code_error);
}

void	free_and_finish(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_a && stack_a)
	{
		while (*stack_a)
		{
			temp = *stack_a;
			*stack_a = (*stack_a)->next;
			free(temp);
		}
	}
	if (*stack_b && stack_b)
	{
		while (*stack_b)
		{
			temp = *stack_b;
			*stack_b = (*stack_b)->next;
			free(temp);
		}
	}
	exit(0);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
