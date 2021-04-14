/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:37:50 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/14 17:14:40 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_all *all;
    int i;

    i = 0;
    if (ac < 2)
        exit(1);
    else
    {
        all = initial(ac, all);
        if (ac == 2)
            all->split = ft_split(av[1], ' ');
        else
            all->split = &av[1];
        check_replicat(all->split);
        check_ascii(all->split);
        put_in_list(all, all->split);
        if (ac == 2)
        {
            while (all->split[i])
            {
                free_arg(&all->split[i]);
                all->split[i] = NULL;
                i++;
            }
            free_arg(all->split);
            all->split = NULL;
        }
        all->len = size_list(all->a);
        if (all->len <= 10)
            sort_min(&(all->a), &(all->b), all->len);
        else if (all->len > 10 && all->len < 200)
            algo_1(&(all->a), &(all->b), all->len);
        else
            algo(&(all->a), &(all->b), all->len);
        free_stack(&all->a);
        free_stack(&all->b);
        free(all);
        all = NULL;
    }
}