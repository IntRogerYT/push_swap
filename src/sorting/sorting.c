/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:52:43 by rcamps-v          #+#    #+#             */
/*   Updated: 2026/01/21 13:31:35 by rcamps-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_nbrs(t_stack **a)
{
	int	f;
	int	s;
	int	t;

	f = (*a)->index;
	s = (*a)->next->index;
	t = (*a)->next->next->index;
	if (f > s && s < t && f < t)
		ft_sa(a);
	else if (f > s && s > t)
	{
		ft_sa(a);
		ft_rra(a);
	}
	else if (f > s && s < t && f > t)
		ft_ra(a);
	else if (f < s && s > t && f < t)
	{
		ft_sa(a);
		ft_ra(a);
	}
	else if (f < s && s > t && f > t)
		ft_rra(a);
}

void	four_five_nbrs(t_stack **stack_a, t_stack **stack_b, int curr_size)
{
	int	pos;

	while (curr_size > 3)
	{
		pos = get_min_pos(*stack_a);
		if (pos <= curr_size / 2)
			while (pos-- > 0)
				ft_ra(stack_a);
		else
			while (pos++ < curr_size)
				ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
		curr_size--;
	}
	sort_five_nbrs(stack_a, stack_b);
}

void	sort_short(t_stack **stack_a, t_stack **stack_b, int curr_size)
{
	t_stack	*last;

	if (curr_size == 2)
	{
		ft_sa(stack_a);
		free_and_finish(stack_a, stack_b);
	}
	else if (curr_size == 3)
	{
		last = ft_lstlast(*stack_a);
		three_nbrs(stack_a);
	}
	else
		four_five_nbrs(stack_a, stack_b, curr_size);
	free_and_finish(stack_a, stack_b);
}

void	sort_time(t_stack **stack_a, t_stack **stack_b, int i)
{
	int		curr_size;
	char	*binary;

	curr_size = ft_lstsize(*stack_a);
	if (curr_size <= 5)
		sort_short(stack_a, stack_b, curr_size);
	binary = malloc(sizeof(char) * 33);
	if (!binary)
		free_stacks(1, stack_a, stack_b);
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
