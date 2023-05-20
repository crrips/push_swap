/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:31:54 by apiloian          #+#    #+#             */
/*   Updated: 2023/04/13 13:31:54 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	digit_check(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (str[0] == '-')
			str++;
		if (*str >= '0' && *str <= '9')
			i++;
		str++;
	}
	if (!i)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	digit_check2(char *str)
{
	while (*str)
	{
		if (str[0] == '-')
			str++;
		if (*str < '0' || *str > '9')
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		str++;
	}
}

void	big_nbr(char *str)
{
	char	*nbr;

	nbr = ft_itoa(ft_atoi(str));
	if (ft_strncmp(str, nbr, ft_strlen(str)) != 0)
	{
		write(2, "Error\n", 6);
		free(nbr);
		exit(1);
	}
	free(nbr);
}

void	dup3(char *str, char **argv)
{
	int		count;
	char	*tmp;

	count = 0;
	while (*argv)
	{
		tmp = *argv;
		while (*tmp == '0' && *(tmp + 1) == '0')
			tmp++;
		if (ft_strncmp(str, tmp, ft_strlen(str)) == 0
			&& (ft_strncmp(str, tmp, ft_strlen(tmp))) == 0)
			count++;
		if (count > 1)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		argv++;
	}
}

void	errors(char *str, char **argv)
{	
	while (*str == '0' && (*(str + 1) >= '0' && *(str + 1) <= '9'))
		str++;
	digit_check2(str);
	big_nbr(str);
	dup3(str, argv);
}
