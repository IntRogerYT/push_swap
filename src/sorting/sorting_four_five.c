/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_four_five.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:10:23 by rcamps-v          #+#    #+#             */
/*   Updated: 2026/01/16 12:12:52 by rcamps-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_nbrs(t_stack **stack_a, t_stack **stack_b)
{
	three_nbrs(stack_a, stack_b, &((*stack_a)->next));
	while (*stack_b != NULL)
		ft_pa(stack_a, stack_b);
	free_and_finish(stack_a, stack_b);
}
