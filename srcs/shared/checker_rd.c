/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:15:44 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/21 03:29:30 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_condition_(char **str)
{
	ft_free_split(str);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	condition_(char *line)
{
	char	**str;
	 int	i;

	str = ft_split(line, '\n');
	i = 0;
	while (str[i])
	{
		if (condition(str[i]) == 1)
		{
			i++;
			continue ;
		}
		else
			free_condition_(str);
	}
	ft_free_split(str);
	return (1);
}

void	checker_pars_v(t_stack **a, t_stack **b, char *line)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!ft_strcmp(line, "sa\n") && size_list(*a) > 1)
		swap_stack(a);
	else if (!ft_strcmp(line, "ra\n") && size_list(*a) > 1)
		r_stack(a);
	else if (!ft_strcmp(line, "rra\n") && size_list(*a) > 1)
		rr_stack(a, tmp);
	else if (!ft_strcmp(line, "sb\n") && size_list(*b) > 1)
		swap_stack(b);
	else if (!ft_strcmp(line, "rb\n") && size_list(*b) > 1)
		r_stack(b);
	else if (!ft_strcmp(line, "rrb\n") && size_list(*b) > 1)
		rr_stack(b, tmp);
	else if (!ft_strcmp(line, "pb\n"))
		push_stack(a, b, tmp);
	else if (!ft_strcmp(line, "pa\n"))
		push_stack(b, a, tmp);
	else if (!ft_strcmp(line, "ss\n") && size_list(*b) > 1 && size_list(*a) > 1)
		ss(a, b);
	else if (!ft_strcmp(line, "rr\n") && size_list(*b) > 1 && size_list(*a) > 1)
		rr(a, b);
	else if (!ft_strcmp(line, "rrr\n") && size_list(*b) > 1 && size_list(*a) > 1)
		rrr(a, b);
}
