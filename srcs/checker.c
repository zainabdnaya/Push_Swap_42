/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:38:54 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/22 02:58:29 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*string(t_all *all, char *tmp)
{
	char	*str;

	str = NULL;
	all->line = malloc(sizeof(char) * BUFFER_SIZE);
	ft_bzero(all->line, BUFFER_SIZE);
	while (read(0, all->line, BUFFER_SIZE))
	{
		tmp = str;
		if (str == NULL)
			str = ft_strdup(all->line);
		else
			str = ft_strjoin(str, all->line);
		if (all->ac >=  2 && !ft_strchr(all->av[1],' '))
			condition_(all->line);
		if (tmp)
		{
			free(tmp);
			tmp = NULL;
		}
		free_arg(&all->line);
		all->line = malloc(sizeof(char) * BUFFER_SIZE);
		ft_bzero(all->line, BUFFER_SIZE);
	}
	return (str);
}

char	**checker_norm(t_all *all, char **line, char *tmp)
{
	char	*l;

	l = string(all, tmp);
	if (l)
	{
		line = ft_split(l, '\n');
		free_arg(&l);
	}
	else
		checker_sort(all);
	return (line);
}

void	the_end(t_all *all, char **line, int i)
{
	while (line[i])
	{
		if (all->ac <= 2)
		{
			checker_pars(&all->a, &all->b, line[i]);
			i++;
		}
		else
		{
			if (condition(line[i]) == 1)
			{
				checker_pars(&all->a, &all->b, line[i]);
				i++;
			}
			else
			{
				ft_free_split(line);
				free_stack(&all->a);
				free_stack(&all->b);
				free(all);
				ft_putstr_fd("Error\n", 2);
				exit(1);
			}
		}
	}
}

void	checker(t_all *all, char **line)
{
	char	*tmp;
	 int	i;

	i = 0;
	tmp = NULL;
	line = checker_norm(all, line, tmp);
	the_end(all, line, i);
	ft_free_split(line);
	checker_sort(all);
}

int	main(int ac, char **av)
{
	t_all	*all;
	 char	**line;

	line = NULL;
	all = NULL;
	if (ac < 2)
		exit(1);
	else
	{
		all = initial(all);
		all->ac = ac;
		all->av = av;
		if (!ft_strcmp(av[1], "-v"))
			option_v(all, ac, av);
		else
		{
			all->split = normal(all, ac, av);
			all = fill_in(all);
			checker(all, line);
		}
	}
}
