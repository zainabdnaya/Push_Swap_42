/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:37:50 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/13 23:37:07 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void sort_a_3(t_stack **a, t_stack **b, int len);
void sort_min(t_stack **a, t_stack **b, int len);

int main(int ac, char **av)
{
    t_all *all;
    if (ac < 2)
        exit(1);
    else
    {
        int i;
    
        i = 1;
        all = initial(ac,all);
        while(av[i])
        {
            all->split = ft_split(av[i],' ');
            i++;
        }
        check_replicat(all->split); 
        check_ascii(all->split);
        all->a = put_in_list(all,all->split);
        all->len = size_list(all->a);
        if (all->len <= 10)
            sort_min(&(all->a), &(all->b), all->len);
        else if (all->len > 10 && all->len < 200)
            algo_1(&(all->a), &(all->b), all->len);
        else
            algo(&(all->a), &(all->b), all->len);
        // print_list(all->a);
    }
}