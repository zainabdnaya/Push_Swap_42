/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:37:50 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/20 14:49:33 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_all *fill_ps(t_all *all)
{
    t_stack *new;

    new = NULL;
    check_replicat(all->split);
    check_ascii(all->split);
    all->a = put_in_list(all, all->split, new);
    all->len = size_list(all->a);
    free_stack(&new);
    return (all);
}

void swap_(t_all *all, int ac, char **av)
{
    if (!ft_strcmp(av[1], "-s"))
    { 
        all->fd = open("swap.log", O_CREAT | O_RDWR ,0666);
            if (all->fd == -1)
            ft_putstr_fd("Error! opening file",1);
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
    all = fill_in(all);
    if (all->len <= 10)
        sort_min(&(all->a), &(all->b), all->len,all);
    else if (all->len > 10 && all->len < 200)
        algo_1(&(all->a), &(all->b), all->len,all);
    else
        algo(&(all->a), &(all->b), all->len,all);
    if (ac == 2 || ac == 3)
        ft_free_split(all->split);
    close(all->fd);
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
        all = initial(all);
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