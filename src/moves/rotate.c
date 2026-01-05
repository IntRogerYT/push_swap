/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:03:24 by rcamps-v          #+#    #+#             */
/*   Updated: 2026/01/05 15:00:21 by rcamps-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*ptr1;
	t_stack	*ptr2;
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	ptr1 = *stack;
	ptr2 = (*stack)->next;
	last_node = *stack;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = ptr1;
	ptr1->next = NULL;
	*stack = ptr2;
}

void	ft_ra(t_stack **stack)
{
	ft_rotate(stack);
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack **stack)
{
	ft_rotate(stack);
	write(1, "rb\n", 3);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
}
