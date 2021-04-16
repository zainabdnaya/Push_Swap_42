/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:48:46 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/16 16:57:12 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_(t_all *all, int ac, char **av)
{
    if (ac == 2)
        all->split = ft_split(av[1], ' ');
    else
        all->split = &av[1];
    check_replicat(all->split);
    check_ascii(all->split);
    put_in_list(all, all->split);

    all->len = size_list(all->a);
    if (all->len <= 10)
        sort_min(&(all->a), &(all->b), all->len);
    else if (all->len > 10 && all->len < 200)
        algo_1(&(all->a), &(all->b), all->len);
    else
        algo(&(all->a), &(all->b), all->len);
}

void swap_c(t_all *all, int ac, char **av)
{
    if (ac == 3)
        all->split = ft_split(av[2], ' ');
    else
        all->split = &av[2];
    check_replicat(all->split);
    check_ascii(all->split);
    all->a = put_in_list(all, all->split);
    all->len = size_list(all->a);
    if (all->len <= 10)
        sort_min_c(&(all->a), &(all->b), all->len);
    else if (all->len > 10 && all->len < 200)
        algo_1_c(&(all->a), &(all->b), all->len);
    else
        algo_c(&(all->a), &(all->b), all->len);
}
void swap_sh(t_all *all, int ac, char **av)
{
    if (ac == 3)
        all->split = ft_split(av[2], ' ');
    else
        all->split = &av[2];
    check_replicat(all->split);
    check_ascii(all->split);
    all->a = put_in_list(all, all->split);
    print_all(all->a, all->b);
    all->len = size_list(all->a);
    if (all->len <= 10)
        sort_min_d(&(all->a), &(all->b), all->len);
    else if (all->len > 10 && all->len < 200)
        algo_1_d(&(all->a), &(all->b), all->len);
    else
        algo_d(&(all->a), &(all->b), all->len);
}