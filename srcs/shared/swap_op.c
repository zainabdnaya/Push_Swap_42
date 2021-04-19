/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:48:46 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/19 21:26:23 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void swap_c(t_all *all, int ac, char **av)
{
    t_stack *new;

    new = NULL;
    if (ac == 3)
        all->split = ft_split(av[2], ' ');
    else
        all->split = &av[2];
      all = fill_in(all);
    if (all->len <= 10)
        sort_min_c(&(all->a), &(all->b), all->len);
    else if (all->len > 10 && all->len < 200)
        algo_1_c(&(all->a), &(all->b), all->len);
    else
        algo_c(&(all->a), &(all->b), all->len);
    free_stack(&all->a);
    free_arg(&all->line);
    if (ac == 2)
        ft_free_split(all->split);
}
void swap_sh(t_all *all, int ac, char **av)
{
    t_stack *new;

    new = NULL;
    if (ac == 3)
        all->split = ft_split(av[2], ' ');
    else
        all->split = &av[2];
    all = fill_in(all);
    print_all(all->a, all->b);
    if (all->len <= 10)
        sort_min_d(&(all->a), &(all->b), all->len);
    else if (all->len > 10 && all->len < 200)
        algo_1_d(&(all->a), &(all->b), all->len);
    else
        algo_d(&(all->a), &(all->b), all->len);
    free_stack(&new);
    free_stack(&all->a);
    free_arg(&all->line);
    if (ac == 2)
        ft_free_split(all->split);
}