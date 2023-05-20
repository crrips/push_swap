/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:43:23 by apiloian          #+#    #+#             */
/*   Updated: 2023/05/04 13:10:14 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	split_count(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	check_sort(t_ps *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->nbr < stack->next->nbr)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

t_ps	*last_node(t_ps *head)
{
	if (head)
	{
		while (head->next)
			head = head->next;
		return (head);
	}
	return (0);
}

void	find_index(t_ps **stack, int nbrs)
{
	int		index;
	int		min;
	t_ps	*cur;

	index = 0;
	while (index < nbrs - 1)
	{
		cur = *stack;
		min = INT32_MAX;
		while (cur)
		{
			if ((cur)->nbr <= min && (cur)->index == -1)
				min = (cur)->nbr;
			if (!(cur)->next)
				break ;
			cur = (cur)->next;
		}
		while ((cur)->nbr != min)
			cur = (cur)->prev;
		(cur)->index = index;
		index++;
	}
}
