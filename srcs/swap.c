/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:37:50 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/19 06:47:45 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void swap_(t_all *all, int ac, char **av)
{
    t_stack *new;

    new = NULL;
    if (ac == 2)
        all->split = ft_split(av[1], ' ');
    else
        all->split = &av[1];
    check_replicat(all->split);
    check_ascii(all->split);
    put_in_list(all, all->split, new);
    all->len = size_list(all->a);
    if (all->len <= 10)
        sort_min(&(all->a), &(all->b), all->len);
    else if (all->len > 10 && all->len < 200)
        algo_1(&(all->a), &(all->b), all->len);
    else
        algo(&(all->a), &(all->b), all->len);
    if (ac == 2)
        ft_free_split(all->split);
}

int main(int ac, char **av)
{
    t_all *all;
    int i;

    all = NULL;
    i = 0;
    if (ac < 2)
        exit(1);
    else
    {
        all = initial(ac, all);
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