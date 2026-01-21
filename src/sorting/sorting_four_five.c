/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_four_five.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:10:23 by rcamps-v          #+#    #+#             */
/*   Updated: 2026/01/21 12:22:54 by rcamps-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_nbrs(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*next;

	next = (*stack_a)->next;
	three_nbrs(stack_a);
	while (*stack_b != NULL)
		ft_pa(stack_a, stack_b);
	free_and_finish(stack_a, stack_b);
}

int	get_min_pos(t_stack *stack)
{
	int		pos;
	int		min_pos;
	t_stack	*min_node;

	if (!stack)
		return (-1);
	pos = 0;
	min_pos = 0;
	min_node = stack;
	while (stack)
	{
		if (stack->index < min_node->index)
		{
			min_node = stack;
			min_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (min_pos);
}
