/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:00:20 by apiloian          #+#    #+#             */
/*   Updated: 2023/05/03 17:45:22 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_ps **stack)
{
	int	tmp;
	int	ind;

	if (!*stack)
		return ;
	if ((*stack)->next)
	{
		tmp = (*stack)->nbr;
		ind = (*stack)->index;
		(*stack)->nbr = (*stack)->next->nbr;
		(*stack)->index = (*stack)->next->index;
		*stack = (*stack)->next;
		(*stack)->nbr = tmp;
		(*stack)->index = ind;
		*stack = (*stack)->prev;
	}
}

void	sa(t_ps **stack, int flag)
{
	swap(stack);
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	sb(t_ps **stack, int flag)
{
	swap(stack);
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ss(t_ps **a, t_ps **b)
{
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n", 3);
}
