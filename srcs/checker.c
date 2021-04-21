/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:38:54 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/21 04:40:24 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*string(t_all *all, char *str, char *tmp)
{
	while (read(0, all->line, BUFFER_SIZE))
	{
		tmp = str;
		condition_(all->line);
		if (str == NULL)
			str = ft_strdup(all->line);
		else
			str = ft_strjoin(str, all->line);
		if (tmp)
		{
			free(tmp);
			tmp = NULL;
		}
	}
	return (str);
}

char	**checker_norm(t_all *all, char *str, char **line, char *tmp)
{
	all->line = ft_calloc(BUFFER_SIZE, sizeof(char));
	str = string(all, str, tmp);
	if (!ft_strcmp(all->line, "\0"))
		checker_sort(all);
	free_arg(&all->line);
	if (str)
	{
		line = ft_split(str, '\n');
		free_arg(&str);
	}
	else
		exit(1);
	return (line);
}

void	checker(t_all *all, char *str, char **line)
{
	char	*tmp;
	 int	i;

	i = 0;
	tmp = NULL;
	line = checker_norm(all, str, line, tmp);
	while (line[i])
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
	ft_free_split(line);
	checker_sort(all);
}

int	main(int ac, char **av)
{
	t_all	*all;
	 char	**line;
	 char	*str;

	str = NULL;
	line = NULL;
	all = NULL;
	if (ac < 2)
		exit(1);
	else
	{
		all = initial(all);
		if (!ft_strcmp(av[1], "-v"))
			option_v(all, ac, av);
		else
		{
			all->split = normal(all, ac, av);
			all = fill_in(all);
			checker(all, str, line);
		}
	}
}
