/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <rcamps-v@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 13:18:04 by rcamps-v          #+#    #+#             */
/*   Updated: 2026/01/05 15:03:33 by rcamps-v         ###   ########.fr       */
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
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
// === Swap ===
void	ft_swap(t_stack **stack);
void	ft_sa(t_stack **stack);
void	ft_sb(t_stack **stack);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
// === Push ===
void	ft_push(t_stack **stack_start, t_stack **stack_dest);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
// === Rotate ===
void	ft_rotate(t_stack **stack);
void	ft_ra(t_stack **stack);
void	ft_rb(t_stack **stack);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
// === Reverse rotate ===
void	ft_reverse_rotate(t_stack **stack);
void	ft_rra(t_stack **stack);
void	ft_rrb(t_stack **stack);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
#endif
