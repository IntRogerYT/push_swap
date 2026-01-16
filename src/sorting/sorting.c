/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:52:43 by rcamps-v          #+#    #+#             */
/*   Updated: 2026/01/16 14:26:41 by rcamps-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_nbrs(t_stack **stack_a, t_stack **stack_b, t_stack **next)
{
	*next = (*stack_a)->next;
	if ((*stack_a)->index == 1)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if ((*stack_a)->index == 2)
	{
		if ((*next)->index == 1)
			ft_sa(stack_a);
		else
			ft_rra(stack_a);
	}
	else
	{
		if ((*next)->index == 2)
		{
			ft_sa(stack_a);
			ft_rra(stack_a);
		}
		else
			ft_ra(stack_a);
	}
	if (!*stack_b)
		free_and_finish(stack_a, stack_b);
}

void	four_five_nbrs(t_stack **stack_a, t_stack **stack_b, int curr_size)
{
	t_stack	*temp;
	int		i;

	temp = *stack_a;
	i = 0;
	while (curr_size-- > 3)
	{
		while (temp->index > 0)
		{
			temp = temp->next;
			i++;
		}
		if (i-- > 2)
		{
			while (++i < curr_size)
				ft_rra(stack_a);
		}
		else if (i++ <= 2)
		{
			while (--i > 0)
				ft_ra(stack_a);
		}
		ft_pb(stack_a, stack_b);
	}
	sort_five_nbrs(stack_a, stack_b);
}

void	sort_short(t_stack **stack_a, t_stack **stack_b, int curr_size)
{
	t_stack	*next;

	if (curr_size == 2)
	{
		ft_sa(stack_a);
		free_and_finish(stack_a, stack_b);
	}
	else if (curr_size == 3)
		three_nbrs(stack_a, stack_b, &next);
	else
		four_five_nbrs(stack_a, stack_b, curr_size);
}

void	sort_time(t_stack **stack_a, t_stack **stack_b, int i)
{
	int		curr_size;
	char	*binary;

	binary = malloc(sizeof(char) * 33);
	if (!binary)
		free_stacks(1, stack_a, stack_b);
	curr_size = ft_lstsize(*stack_a);
	if (curr_size <= 5)
		sort_short(stack_a, stack_b, curr_size);
	while (curr_size--)
	{
		binary_conversion((*stack_a)->index, &binary);
		if (binary[i] == '0')
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
	}
	free(binary);
	while (*stack_b)
		ft_pa(stack_a, stack_b);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int *size)
{
	int	i;
	int	max_bits;
	int	max_num;

	if (!*stack_a || !*size || check_order(*stack_a, *size))
		free_and_finish(stack_a, stack_b);
	max_num = *size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		sort_time(stack_a, stack_b, 31 - i);
		if (check_order(*stack_a, *size))
			break ;
		i++;
	}
	free_and_finish(stack_a, stack_b);
}
