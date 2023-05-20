/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:07:43 by apiloian          #+#    #+#             */
/*   Updated: 2023/05/03 17:34:04 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	rotate(t_ps **stack)
{
	t_ps	*last;

	if (*stack)
	{
		last = last_node(*stack);
		last->next = *stack;
		(*stack)->prev = last;
		*stack = (*stack)->next;
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
}

void	ra(t_ps **stack)
{
	rotate(stack);
}

void	rb(t_ps **stack)
{
	rotate(stack);
}

void	rr(t_ps **a, t_ps **b)
{
	ra(a);
	rb(b);
}
