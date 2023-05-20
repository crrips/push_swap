/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:00:20 by apiloian          #+#    #+#             */
/*   Updated: 2023/05/03 17:45:38 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

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

void	sa(t_ps **stack)
{
	swap(stack);
}

void	sb(t_ps **stack)
{
	swap(stack);
}

void	ss(t_ps **a, t_ps **b)
{
	sa(a);
	sb(b);
}
