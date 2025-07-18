/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-mawl <kal-mawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:20:56 by kal-mawl          #+#    #+#             */
/*   Updated: 2025/07/16 09:15:28 by kal-mawl         ###   ########.fr       */
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
}t_stack;
int		ft_atoi(const char *str);
int		find_min(t_stack *stack);
int		find_position(t_stack *stack, int target);
int		is_sorted(t_stack *stack);
int		validate_input(int argc, char **argv);
long	ft_atol(const char *str);
int		ft_isdigit(int c);
int		stack_size(t_stack *stack);
void	pa(t_stack **a, t_stack **b, int print);
void	init_stack(t_stack **stack, char **args);
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
void	radix_sort(t_stack **a, t_stack **b);
void	index_stack(t_stack *stack);
char	**ft_split(const char *s, char c);
void	free_stack(t_stack **stack);

#endif