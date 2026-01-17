/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <rcamps-v@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:47:36 by rcamps-v          #+#    #+#             */
/*   Updated: 2026/01/17 15:15:23 by rcamps-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stack **stack_a, t_stack **stack_b, int *size)
{
	set_index(stack_a, *size);
	radix_sort(stack_a, stack_b, size);
	free_and_finish(stack_a, stack_b);
}

void	check_input(char *args)
{
	char	**matrix;
	int		i;

	i = 0;
	matrix = ft_split(args, ' ');
	while (matrix[i])
		i++;
	if (i == 1)
	{
		free(matrix);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*clean_input;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	size = 0;
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		check_input(argv[1]);
		clean_input = parse_one_arg(argv[1], &size);
	}
	else
	{
		clean_input = validate_and_parse(argc, argv, &size);
		if (!clean_input)
			return (write(1, "Error\n", 6), 0);
	}
	lst_conversion(&stack_a, clean_input, size);
	sorting(&stack_a, &stack_b, &size);
	return (0);
}
