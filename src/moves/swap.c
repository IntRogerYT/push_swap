/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <rcamps-v@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 13:25:23 by rcamps-v          #+#    #+#             */
/*   Updated: 2026/01/04 16:09:58 by rcamps-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*ptr1;
	t_stack	*ptr2;

	if (!*stack || !(*stack)->next)
		return ;
	ptr1 = *stack;
	ptr2 = ptr1->next;
	ptr1->next = ptr2->next;
	ptr2->next = ptr1;
	*stack = ptr2;
}

void	ft_sa(t_stack **stack)
{
	ft_swap(stack);
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack **stack)
{
	ft_swap(stack);
	write(1, "sb\n", 3);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	write(1, "ss\n", 3);
}
