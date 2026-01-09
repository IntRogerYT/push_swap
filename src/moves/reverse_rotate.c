/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:32:19 by rcamps-v          #+#    #+#             */
/*   Updated: 2026/01/09 12:21:36 by rcamps-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*iter;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	iter = *stack;
	while (iter->next != last)
		iter = iter->next;
	iter->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	ft_rra(t_stack	**stack)
{
	ft_reverse_rotate(stack);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **stack)
{
	ft_reverse_rotate(stack);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
