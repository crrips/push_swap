/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:55:11 by apiloian          #+#    #+#             */
/*   Updated: 2023/04/20 19:55:11 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	free_exit(char *tmp, char **spl)
{
	free(tmp);
	free_arr(spl);
	exit(0);
}

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
	if (len == 1 && argc == 2)
		free_exit(tmp, spl);
	if (check_sort(*a))
		free_exit(tmp, spl);
	free_arr(spl);
	free(tmp);
	return (len);
}

int	main(int argc, char **argv)
{
	t_ps	*a;
	t_ps	*b;
	int		len;

	if (argc > 1)
	{
		a = NULL;
		b = NULL;
		len = parsing(argc, argv, &a);
		find_index(&a, len + 1);
		sort(&a, &b, len + 1);
	}
	return (0);
}
