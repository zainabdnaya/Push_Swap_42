/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:48:46 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/17 02:50:47 by zainabdnaya      ###   ########.fr       */
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
    put_in_list(all, all->split,new);
    free_stack(&new);
    all->len = size_list(all->a);
    if (all->len <= 10)
        sort_min(&(all->a), &(all->b), all->len);
    // else if (all->len > 10 && all->len < 200)
    //     algo_1(&(all->a), &(all->b), all->len);
    // else
    //     algo(&(all->a), &(all->b), all->len);
    //     if (new)
    // {
    //     free(new);
    //     new = NULL;
    // }
    the_end(&(all->a), &(all->b),&all->line, all);
}

// void swap_c(t_all *all, int ac, char **av)
// {
//     if (ac == 3)
//         all->split = ft_split(av[2], ' ');
//     else
//         all->split = &av[2];
//     check_replicat(all->split);
//     check_ascii(all->split);
//     all->a = put_in_list(all, all->split);
//     all->len = size_list(all->a);
//     if (all->len <= 10)
//         sort_min_c(&(all->a), &(all->b), all->len);
//     else if (all->len > 10 && all->len < 200)
//         algo_1_c(&(all->a), &(all->b), all->len);
//     else
//         algo_c(&(all->a), &(all->b), all->len);
// }
// void swap_sh(t_all *all, int ac, char **av)
// {
//     if (ac == 3)
//         all->split = ft_split(av[2], ' ');
//     else
//         all->split = &av[2];
//     check_replicat(all->split);
//     check_ascii(all->split);
//     all->a = put_in_list(all, all->split);
//     print_all(all->a, all->b);
//     all->len = size_list(all->a);
//     if (all->len <= 10)
//         sort_min_d(&(all->a), &(all->b), all->len);
//     else if (all->len > 10 && all->len < 200)
//         algo_1_d(&(all->a), &(all->b), all->len);
//     else
//         algo_d(&(all->a), &(all->b), all->len);
// }