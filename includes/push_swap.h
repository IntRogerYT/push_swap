/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <rcamps-v@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 13:18:04 by rcamps-v          #+#    #+#             */
/*   Updated: 2026/01/22 13:02:25 by rcamps-v         ###   ########.fr       */
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
char	**ft_split(char *s, char c);
long	ft_atol(const char *nptr);
int		ft_is_number(const char *nptr);
t_stack	*ft_lstnew(int content);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);
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
void	nums_validation(long *nums_array, int len, char **matrix);
int		*parse_one_arg(char *args, int *size);
int		*ft_atol_and_validation_args(char **matrix);
void	nums_validation_args(long *nums_array, int len, char **matrix);
// === Utils functions ===
void	free_and_exit(int code_error, char **matrix, long *nums_array);
void	free_stacks(int code_error, t_stack **stack_a, t_stack **stack_b);
void	free_and_finish(t_stack **stack_a, t_stack **stack_b);
void	free_matrix(char **matrix);
void	freem_and_exit(char **matrix, void *temp);
void	lst_conversion(t_stack **stack, int *nums_array, int size);
// === Sorting ===
int		has_duplicates(t_stack *stack);
int		get_min_pos(t_stack *stack);
void	binary_conversion(int n, char **binary);
t_stack	*find_lowest(t_stack *stack);
void	set_index(t_stack **stack, int size);
int		check_order(t_stack *stack, int size);
void	radix_sort(t_stack **stack_a, t_stack **stack_b, int *size);
void	sort_time(t_stack **stack_a, t_stack **stack_b, int i);
void	sort_short(t_stack **stack_a, t_stack **stack_b, int curr_size);
void	three_nbrs(t_stack **a);
void	four_five_nbrs(t_stack **stack_a, t_stack **stack_b, int curr_size);
void	sort_five_nbrs(t_stack **stack_a, t_stack **stack_b);
// === Main function ===
int		ft_numlen(char *s);
int		max_min_int(char *str);
void	sorting(t_stack **stack_a, t_stack **stack_b, int *size);
void	check_input(char *args);
int		main(int argc, char **argv);
#endif
