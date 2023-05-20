/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:07:43 by apiloian          #+#    #+#             */
/*   Updated: 2023/05/03 17:46:40 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ra(t_ps **stack, int flag)
{
	rotate(stack);
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	rb(t_ps **stack, int flag)
{
	rotate(stack);
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	rr(t_ps **a, t_ps **b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}
