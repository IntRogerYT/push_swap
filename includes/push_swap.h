/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <rcamps-v@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 13:18:04 by rcamps-v          #+#    #+#             */
/*   Updated: 2026/01/04 16:14:26 by rcamps-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
/********************************/
/*        EXTERN LIBS           */
/********************************/
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
/********************************/
/*           MACROS             */
/********************************/

/********************************/
/*          VARIABLES           */
/********************************/

/********************************/
/*           STRUCTS            */
/********************************/
typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

/********************************/
/*          FUNCTIONS           */
/********************************/
// === libft functions ===
// === Swap ===
void	ft_swap(t_stack **stack);
void	ft_sa(t_stack **stack);
void	ft_sb(t_stack **stack);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
// === Push ===
void	ft_push(t_stack **stack_a, t_stack **stack_b);
#endif
