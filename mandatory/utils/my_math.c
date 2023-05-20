/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:06:21 by apiloian          #+#    #+#             */
/*   Updated: 2023/05/03 15:03:28 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	while (n / i != i)
		i++;
	return (i);
}

int	find_n(int n)
{
	int	i;

	i = 1;
	while (n)
	{
		n /= 5;
		i++;
	}
	return (i);
}
