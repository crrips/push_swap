/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s1mple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:48:13 by apiloian          #+#    #+#             */
/*   Updated: 2023/05/03 15:03:36 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort3(t_ps **a)
{
	t_ps	*last;

	if (check_sort(*a))
		return ;
	last = last_node(*a);
	if ((*a)->nbr < (*a)->next->nbr && (*a)->nbr < last->nbr)
	{
		ra(a, 1);
		sa(a, 1);
		rra(a, 1);
	}
	if ((*a)->nbr > (*a)->next->nbr && (*a)->nbr > last->nbr)
	{
		rra(a, 1);
		rra(a, 1);
	}
	if ((*a)->next->nbr < (*a)->nbr && (*a)->nbr < last->nbr)
		sa(a, 1);
	if (last->nbr < (*a)->nbr && last->nbr < (*a)->next->nbr)
		rra(a, 1);
	if ((*a)->next->nbr < (*a)->nbr)
		sa(a, 1);
}

void	sort5(t_ps **a, t_ps **b)
{
	if (last_node(*a)->index == 0 || last_node(*a)->prev->index == 0)
		while ((*a)->index != 0)
			rra(a, 1);
	else
		while ((*a)->index != 0)
			ra(a, 1);
	pb(b, a);
	if (last_node(*a)->index == 1 || last_node(*a)->prev->index == 1)
		while ((*a)->index != 1)
			rra(a, 1);
	else
		while ((*a)->index != 1)
			ra(a, 1);
	pb(b, a);
	if (check_sort(*b))
		rb(b, 1);
	sort3(a);
	pa(a, b);
	pa(a, b);
}

int	s1mple(t_ps **a, t_ps **b, int nbrs)
{
	if (nbrs == 2)
	{
		ra(a, 1);
		return (1);
	}
	if (nbrs == 3)
	{
		sort3(a);
		return (1);
	}
	if (nbrs == 5)
	{
		sort5(a, b);
		return (1);
	}
	return (0);
}
