/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <rcamps-v@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:47:36 by rcamps-v          #+#    #+#             */
/*   Updated: 2026/01/08 14:33:51 by rcamps-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*clean_input;
	int	size;
	int	i;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		write(1, &argv[1], sizeof(argv[1]));
		return (1);
	}
	clean_input = validate_and_parse(argc, argv, &size);
	if (!clean_input)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (i < size)
	{
		printf("%i\n", clean_input[i]);
		i++;
	}
	return (0);
}
