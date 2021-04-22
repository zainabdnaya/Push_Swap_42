/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:37:50 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/22 01:45:28 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**fill_ps(t_all *all, int ac, char **av)
{
	if (!ft_strcmp(av[1], "-s"))
	{
		all->fd = open("swap.log", O_CREAT | O_RDWR | O_TRUNC, 0666);
		if (all->fd == -1)
			ft_putstr_fd("Error! opening file", 1);
		if (ac == 3)
			all->split = ft_split(av[2], ' ');
		else
			all->split = &av[2];
	}
	else
	{
		all->fd = 1;
		if (ac == 2)
			all->split = ft_split(av[1], ' ');
		else
			all->split = &av[1];
	}
	return (all->split);
}

void	swap_(t_all *all, int ac, char **av)
{
	t_stack	*new;

	new = NULL;
	all->split = fill_ps(all, ac, av);
	check_replicat(all->split);
	check_ascii(all->split);
	all->a = put_in_list(all, all->split, new);
	if (check_sort(&all->a, size_list(all->a)) == 1)
		exit(0);
	all->len = size_list(all->a);
	free_stack(&new);
	if (all->len <= 10)
		sort_min(&(all->a), &(all->b), all->len, all);
	else if (all->len > 10 && all->len < 200)
		algo_1(&(all->a), &(all->b), all->len, all);
	else
		algo(&(all->a), &(all->b), all->len, all);
	if (ac == 2 || (ac == 3 && all->fd != 1))
		ft_free_split(all->split);
	close(all->fd);
}

void	text(void)
{
	char	*str;

	str = "Run this command it should give OK \xE2\x9C\x85 for no Existing Errors";
	ft_putstr_fd("\t\033[94m\xE2\x9C\xA8Welcome to PUSH_SWAP\xE2\x9C\xA8 \033[94m\t\n", 1);
	ft_putstr_fd("\033[36mTo run Push_swap\xE2\x9D\x97:\n", 1);
	ft_putstr_fd("\033[35m ./push_swap list_of_numbers_given_as_parameters\n", 1);
	ft_putstr_fd("\033[92m exemple (./push_swap 4 3 7)\n", 1);
	ft_putstr_fd("\033[36mTo run Checker\xE2\x9D\x97:\n", 1);
	ft_putstr_fd("\033[35m ./checker number_list\n", 1);
	ft_putstr_fd("\033[92m exemple (./checker 4 3 7)\n", 1);
	ft_putstr_fd("\033[94mTo Check if push_swap work well\xF0\x9F\x91\x8C:\n", 1);
	ft_putstr_fd("\033[94m\xF0\x9F\x8F\x83str\n", 1);
	ft_putstr_fd("\033[35m ./push_swap number_list | ./checker number_list\n", 1);
	ft_putstr_fd("\033[92m exemple (./push_swap 4 3 7 | ./checker 4 3 7 )\n", 1);
	ft_putstr_fd("\t\t\033[30m\033[41m Output: OK!\n", 1);
	exit(0);
}

int	main(int ac, char **av)
{
	t_all	*all;

	all = NULL;
	if (ac < 2)
		exit(1);
	else
	{
		all = initial(all);
		if (!ft_strcmp(av[1], "-h"))
			text();
		if (!ft_strcmp(av[1], "-c"))
			swap_c(all, ac, av);
		else if (!ft_strcmp(av[1], "-sh"))
			swap_sh(all, ac, av);
		else
			swap_(all, ac, av);
		free(all);
		all = NULL;
	}
}
