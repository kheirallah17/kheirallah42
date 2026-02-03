/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khairallahmawla <khairallahmawla@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:20:56 by kal-mawl          #+#    #+#             */
/*   Updated: 2025/10/02 08:48:16 by khairallahm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;
void	sort_two(t_stack **a);
void	exit_error(void);
void	stack_add_back(t_stack **stack, int value);
void	ft_parse(t_stack **stack, int ac, char **av);
int	is_valid_number(char *s);
int	has_duplicate(t_stack *stack, int nb);
int		ft_atoi(const char *str);
int		find_max(t_stack *stack);
int		find_min(t_stack *stack);
int		is_sorted(t_stack *stack);
int		stack_size(t_stack *stack);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void    sort_two(t_stack **a);
void	pa(t_stack **a, t_stack **b, int print);
void	free_split(char **array);
void	pb(t_stack **a, t_stack **b, int print);
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);
void	dispatch_sort(t_stack **a, t_stack **b);
void	radix_sort(t_stack **a, t_stack **b);
void	index_stack(t_stack *stack);
char	**ft_split(const char *s, char *c);
void	free_stack(t_stack **stack);

#endif