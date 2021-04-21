//* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:15:44 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/21 01:21:21 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_condition_(char **str)
{
	   ft_free_split(str);
        ft_putstr_fd("Error\n", 2);
        exit(1);

}
int condition_(char *line)
{
    char **str;
    int i;

    str = ft_split(line,'\n');
    i = 0;
    while (str[i])
    {
        if (!ft_strcmp(str[i], "sa") || !ft_strcmp(str[i], "ra"))
        {
            i++;
            continue;
        }
        else if (!ft_strcmp(str[i], "rra") || !ft_strcmp(str[i], "sb"))
        {
            i++;
            continue;
        }
    else if (!ft_strcmp(str[i], "rb") || !ft_strcmp(str[i], "rrb"))
        {
            i++;
            continue;
        }
    else if (!ft_strcmp(str[i], "pb") || !ft_strcmp(str[i], "pa"))
        {
            i++;
            continue;
        }
    else if (!ft_strcmp(str[i], "pa") || !ft_strcmp(str[i], "ss"))
        {
            i++;
            continue;
        }
    else if (!ft_strcmp(str[i], "rrr") || !ft_strcmp(str[i], "rr"))
        {
            i++;
            continue;
        }
    else
	free_condition_(str);
    }
    ft_free_split(str);
    return (1);
}

void checker_pars_v(t_stack **a, t_stack **b, char *line)
{
	t_stack *tmp;

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


