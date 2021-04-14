/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:37:50 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/14 12:09:16 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_all *all;
    if (ac < 2)
        exit(1);
    else
    {
        all = initial(ac, all);
        if (ac == 2)
            all->split = ft_split(av[1], ' ');
        else
            all->split = &av[1];
        all = initial(ac, all);
        if (!ft_strcmp(av[1], "-v"))
            all->print = 1;
        all->split = ft_split(av[1], ' ');
        check_replicat(all->split);
        check_ascii(all->split);
        all->a = put_in_list(all, all->split);
        all->len = size_list(all->a);
        if (all->len <= 10)
            sort_min(&(all->a), &(all->b), all->len);
        else if (all->len > 10 && all->len < 200)
            algo_1(&(all->a), &(all->b), all->len);
        else
            algo(&(all->a), &(all->b), all->len);
    
    }
}