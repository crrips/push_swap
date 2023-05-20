/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:46:43 by apiloian          #+#    #+#             */
/*   Updated: 2023/05/03 14:46:43 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

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

char	*get_next_line(int fd);

int		check_sort(t_ps *stack);
t_ps	*last_node(t_ps *head);
void	free_arr(char **arr);

int		split_count(char **split);
char	*join(int argc, char **argv);
t_ps	*fill(t_ps **a, char **spl, int len);
void	digit_check(char *str);
void	errors(char *str, char **argv);

void	sa(t_ps **stack);
void	sb(t_ps **stack);
void	ss(t_ps **a, t_ps **b);
void	pa(t_ps **to, t_ps **from);
void	pb(t_ps **to, t_ps **from);
void	ra(t_ps **stack);
void	rb(t_ps **stack);
void	rr(t_ps **a, t_ps **b);
void	rra(t_ps **stack);
void	rrb(t_ps **stack);
void	rrr(t_ps **a, t_ps **b);

#endif