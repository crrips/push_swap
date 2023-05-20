/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:06:39 by apiloian          #+#    #+#             */
/*   Updated: 2023/04/14 13:25:30 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_ps **to, t_ps **from)
{
	t_ps	*tmp;

	if (*from)
	{
		tmp = *from;
		*from = (*from)->next;
		if (*from)
			(*from)->prev = NULL;
		tmp->next = *to;
		if (*to)
			(*to)->prev = tmp;
		*to = tmp;
	}
}

void	pa(t_ps **to, t_ps **from)
{
	push(to, from);
	write(1, "pa\n", 3);
}

void	pb(t_ps **to, t_ps **from)
{
	push(to, from);
	write(1, "pb\n", 3);
}
