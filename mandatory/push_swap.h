/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:27:46 by apiloian          #+#    #+#             */
/*   Updated: 2023/04/11 16:27:46 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <libft.h>

typedef struct s_ps
{
	int			nbr;
	int			index;
	struct s_ps	*next;
	struct s_ps	*prev;
}		t_ps;

int		check_sort(t_ps *stack);
t_ps	*last_node(t_ps *head);
void	find_index(t_ps **stack, int nbrs);
void	free_arr(char **arr);
void	sort(t_ps **a, t_ps **b, int nbrs);
int		s1mple(t_ps **a, t_ps **b, int nbrs);

int		ft_sqrt(int n);
int		find_n(int n);

int		split_count(char **split);
char	*join(int argc, char **argv);
t_ps	*fill(t_ps **a, char **spl, int len);
void	digit_check(char *str);
void	errors(char *str, char **argv);

void	sa(t_ps **stack, int flag);
void	sb(t_ps **stack, int flag);
void	ss(t_ps **a, t_ps **b);
void	pa(t_ps **to, t_ps **from);
void	pb(t_ps **to, t_ps **from);
void	ra(t_ps **stack, int flag);
void	rb(t_ps **stack, int flag);
void	rr(t_ps **a, t_ps **b);
void	rra(t_ps **stack, int flag);
void	rrb(t_ps **stack, int flag);
void	rrr(t_ps **a, t_ps **b);

#endif