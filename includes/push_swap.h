/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <rcamps-v@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 13:18:04 by rcamps-v          #+#    #+#             */
/*   Updated: 2026/01/14 12:35:43 by rcamps-v         ###   ########.fr       */
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
# include <stdio.h>
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
	int				index;
	struct s_stack	*next;
}	t_stack;

/********************************/
/*          FUNCTIONS           */
/********************************/
// === libft functions ===
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
long	ft_atol(const char *nptr);
int		ft_is_number(const char *nptr);
t_stack	*ft_lstnew(int content);
void   	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
// === Swap functions ===
void	ft_swap(t_stack **stack);
void	ft_sa(t_stack **stack);
void	ft_sb(t_stack **stack);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
// === Push functions ===
void	ft_push(t_stack **stack_start, t_stack **stack_dest);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
// === Rotate functions ===
void	ft_rotate(t_stack **stack);
void	ft_ra(t_stack **stack);
void	ft_rb(t_stack **stack);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
// === Reverse rotate functions ===
void	ft_reverse_rotate(t_stack **stack);
void	ft_rra(t_stack **stack);
void	ft_rrb(t_stack **stack);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
// === Validate and parse functions ===
int		*validate_and_parse(int argc, char **argv, int *size);
int		num_args(char **args);
char	**remove_first_arg(char **argv);
int		*ft_atol_and_validation(char **matrix);
void	nums_validation(long *nums_array, int len);
int		*parse_one_arg(char *args, int *size);
// === Utils functions ===
void	free_and_exit(int code_error, char **matrix, long *nums_array);
void	lst_conversion(t_stack  **stack, int *nums_array, int size);
// === Sorting ===
void	binary_conversion(t_stack *stack, char *binary);
void	sort_and_print(t_stack **stack_a, t_stack **stack_b, int size);
// === Main function ===
void	nums_validation(long *nums_array, int len);
int		main(int argc, char **argv);
#endif
