/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:52:50 by midfath           #+#    #+#             */
/*   Updated: 2021/12/20 11:51:59 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit (0);
}

static void	ft_check(int ac, char **av)
{
	int		i;
	int		j;
	long	num;

	i = 1;
	while (i < ac)
	{
		num = ft_up_atoi(av[i]);
		if (num > INT_MAX || num < INT_MIN)
			ft_error();
		j = i + 1;
		while (j < ac)
		{
			if (num == ft_up_atoi(av[j]))
				ft_error();
			j++;
		}
		i++;
	}
}

static t_list	*ft_get_num(int ac, char **av)
{
	int		i;
	t_list	*p;
	long	num;

	i = 1;
	p = NULL;
	ft_check(ac, av);
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		ft_lstadd_back(&p, st_newnode((void *)&num));
		i++;
	}
	return (p);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = ft_get_num(ac, av);
	b = NULL;
	if (ac <= 2)
		return (0);
	st_putitright(&a, &b);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
}
