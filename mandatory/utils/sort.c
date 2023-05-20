/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:17:24 by apiloian          #+#    #+#             */
/*   Updated: 2023/05/03 15:03:39 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_ps	*max(t_ps *head)
{
	t_ps	*max;

	max = head;
	while (head)
	{
		if (max->nbr < head->nbr)
			max = head;
		head = head->next;
	}
	return (max);
}

int	get_steps(t_ps	**stack, t_ps *max, int n)
{
	t_ps	*tmp;

	tmp = *stack;
	while (n--)
	{
		tmp = tmp->next;
		if (!tmp)
			break ;
		if (tmp->nbr == max->nbr)
			return (1);
	}
	return (0);
}

void	push2a(t_ps **a, t_ps **b, t_ps *max, int n)
{
	if (get_steps(b, max, n - 5))
		while ((*b)->nbr != max->nbr)
			rb(b, 1);
	else
		while ((*b)->nbr != max->nbr)
			rrb(b, 1);
	if ((*b)->nbr == max->nbr)
		pa(a, b);
}

void	butterfly(t_ps **a, t_ps **b, int counter, int n)
{
	while (*a)
	{
		if ((*a)->index <= counter)
		{
			pb(b, a);
			rb(b, 1);
			counter++;
		}
		else if ((*a)->index <= counter + n)
		{
			pb(b, a);
			counter++;
		}
		else
			ra(a, 1);
	}
	while (*b)
		push2a(a, b, max(*b), n);
}

void	sort(t_ps **a, t_ps **b, int nbrs)
{
	int	counter;
	int	n;

	counter = 0;
	n = 1;
	if (s1mple(a, b, nbrs - 1))
		return ;
	if (nbrs > 10)
		n = ft_sqrt(nbrs) + find_n(nbrs);
	butterfly(a, b, counter, n);
}
