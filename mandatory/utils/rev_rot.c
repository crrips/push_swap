/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:10:10 by apiloian          #+#    #+#             */
/*   Updated: 2023/05/03 17:41:31 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	rra(t_ps **stack, int flag)
{
	rev_rot(stack);
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_ps **stack, int flag)
{
	rev_rot(stack);
	if (flag == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_ps **a, t_ps **b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}
