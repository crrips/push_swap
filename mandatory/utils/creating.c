/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:41:34 by apiloian          #+#    #+#             */
/*   Updated: 2023/05/04 12:37:00 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*join(int argc, char **argv)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 1;
	while (i < argc)
	{
		if (!argv[i] || !*argv[i])
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		digit_check(argv[i]);
		if (i == 1)
			str = ft_strdup(argv[i]);
		else
		{
			tmp = ft_strjoin(str, " ");
			free (str);
			str = ft_strjoin(tmp, argv[i]);
			free(tmp);
		}
		i++;
	}
	return (str);
}

t_ps	*fill(t_ps **a, char **spl, int len)
{
	char	*str;
	t_ps	*push;

	while (len--)
	{	
		str = spl[len];
		while (*str == '0' && *(str + 1) == '0')
			str++;
		errors(str, spl);
		push = malloc(sizeof(t_ps));
		push->prev = NULL;
		push->nbr = ft_atoi(str);
		push->index = -1;
		push->next = *a;
		if (*a)
			(*a)->prev = push;
		*a = push;
		if (!(spl)[len])
			return (*a);
	}
	return (*a);
}
