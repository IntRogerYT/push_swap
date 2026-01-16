/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_to_list_conversion.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:49:25 by rcamps-v          #+#    #+#             */
/*   Updated: 2026/01/16 11:37:47 by rcamps-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_conversion(t_stack	**stack, int *nums_array, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		ft_lstadd_back(stack, ft_lstnew(nums_array[i]));
	free(nums_array);
}
