/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <rcamps-v@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:47:36 by rcamps-v          #+#    #+#             */
/*   Updated: 2026/01/09 14:42:37 by rcamps-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*clean_input;
	int	size;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		if (ft_is_number(argv[1]) == 1)
			free_and_exit(1, NULL, 0);
		write(1, argv[1], ft_strlen(argv[1]));
		return (0);
	}
	clean_input = validate_and_parse(argc, argv, &size);
	if (!clean_input)
		return (write(1, "Error\n", 6), 0);
	return (0);
}
