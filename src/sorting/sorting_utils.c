/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:05:23 by rcamps-v          #+#    #+#             */
/*   Updated: 2026/01/16 12:11:27 by rcamps-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*runner;

	current = stack;
	while (current)
	{
		runner = current->next;
		if (!runner)
			return (0);
		while (runner)
		{
			if (current->content == runner->content)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

void	binary_conversion(int n, char **binary)
{
	int		total_bits;
	int		bit_pos;
	int		i;

	total_bits = sizeof(int) * 8;
	i = 0;
	while (i < total_bits)
	{
		bit_pos = (total_bits -1) - i;
		if ((n >> bit_pos) & 1)
			(*binary)[i] = '1';
		else
			(*binary)[i] = '0';
		i++;
	}
	(*binary)[total_bits] = '\0';
}

t_stack	*find_lowest(t_stack *stack)
{
	t_stack	*lowest;

	lowest = NULL;
	while (stack)
	{
		if (stack->index == -1
			&& (lowest == NULL || stack->content < lowest->content))
		{
			lowest = stack;
		}
		stack = stack->next;
	}
	return (lowest);
}

void	set_index(t_stack **stack, int size)
{
	int		i;
	t_stack	*temp;

	if (has_duplicates(*stack))
		free_stacks(1, stack, NULL);
	temp = *stack;
	while (temp)
	{
		temp->index = -1;
		temp = temp->next;
	}
	i = 0;
	while (i < size)
	{
		temp = find_lowest(*stack);
		if (temp != NULL)
		{
			temp->index = i;
		}
		i++;
	}
}

int	check_order(t_stack *stack, int size)
{
	int	count;

	if (!stack)
		return (0);
	count = 1;
	while (stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
		count++;
	}
	return (count == size);
}
