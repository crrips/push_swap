/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:10:10 by apiloian          #+#    #+#             */
/*   Updated: 2023/05/03 17:40:56 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	rev_rot(t_ps **stack)
{
	t_ps	*last;

	if (*stack)
	{
		last = last_node(*stack);
		last->next = *stack;
		*stack = last;
		if ((*stack)->prev)
		{
			(*stack)->prev->next = NULL;
			(*stack)->prev = NULL;
		}
		(*stack)->next->prev = (*stack);
	}
}

void	rra(t_ps **stack)
{
	rev_rot(stack);
}

void	rrb(t_ps **stack)
{
	rev_rot(stack);
}

void	rrr(t_ps **a, t_ps **b)
{
	rra(a);
	rrb(b);
}
