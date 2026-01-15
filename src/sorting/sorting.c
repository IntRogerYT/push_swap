/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:05:23 by rcamps-v          #+#    #+#             */
/*   Updated: 2026/01/14 15:02:44 by rcamps-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	binary_conversion(t_stack *stack, char *binary)
{
	int		n;
	int		total_bits;
	int		bit_pos;
	int		i;

	if (!stack)
		free_and_exit(1, NULL, 0);
	if (!(stack->content))
		free_and_exit(1, NULL, 0);
	n = stack->content;
	total_bits = sizeof(int) * 8;
	i = 0;
	while (i < total_bits)
	{
		bit_pos = (total_bits -1) - i;
		if ((n >> bit_pos) & 1)
			binary[i] = '1';
		else
			binary[i] = '0';
		i++;
		binary[total_bits] = '\0';
	}
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
