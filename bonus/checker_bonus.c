/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:07:14 by apiloian          #+#    #+#             */
/*   Updated: 2023/05/03 15:07:14 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

// void	print_stacks(t_ps *a, t_ps *b)
// {
// 	write(1, "Stack A:\n", 10);
// 	while (a)
// 	{
// 		ft_putnbr_fd(a->nbr, 1);
// 		ft_putchar_fd(' ', 1);
// 		a = a->next;
// 	}
// 	ft_putchar_fd('\n', 1);
// 	if (!b || !b->nbr)
// 		return ;
// 	write(1, "\nStack B:\n", 11);
// 	while (b)
// 	{
// 		ft_putnbr_fd(b->nbr, 1);
// 		ft_putchar_fd(' ', 1);
// 		b = b->next;
// 	}
// 	ft_putchar_fd('\n', 1);
// }

int	parsing(int argc, char **argv, t_ps **a)
{
	int		len;
	char	**spl;
	char	*tmp;

	tmp = join(argc, argv);
	spl = ft_split(tmp, ' ');
	if (!*spl)
	{
		write(2, "Error\n", 6);
		free(tmp);
		exit(EXIT_FAILURE);
	}
	len = split_count(spl);
	*a = fill(a, spl, len);
	free_arr(spl);
	free(tmp);
	return (len);
}

int	do_instruct2(t_ps **a, t_ps **b, char *str)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
	{
		sa(a);
		return (1);
	}
	else if (ft_strncmp(str, "sb\n", 3) == 0)
	{
		sb(b);
		return (1);
	}
	else if (ft_strncmp(str, "ss\n", 3) == 0)
	{
		ss(a, b);
		return (1);
	}
	else if (ft_strncmp(str, "pa\n", 3) == 0)
	{
		pa(a, b);
		return (1);
	}
	return (0);
}

void	do_instruct(t_ps **a, t_ps **b, char *str)
{
	if (do_instruct2(a, b, str))
		return ;
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		pb(b, a);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		ra(a);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rb(b);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		rra(a);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		rrb(b);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		rrr(a, b);
	else
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

void	get_instruct(t_ps **a, t_ps **b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str || !*str)
		{
			free(str);
			break ;
		}
		do_instruct(a, b, str);
		free(str);
	}
}

int	main(int argc, char **argv)
{
	t_ps	*a;
	t_ps	*b;

	if (argc > 1)
	{
		a = NULL;
		b = NULL;
		parsing(argc, argv, &a);
		get_instruct(&a, &b);
		if (check_sort(a))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	return (0);
}
