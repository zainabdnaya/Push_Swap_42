/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_v.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 06:49:20 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/04/19 06:51:26 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void option_v(t_all *all, int ac, char **av)
{
    if (ac == 3)
        all->split = ft_split(av[2], ' ');
    else
        all->split = &av[2];
    all = fill_in(all);
    while (1)
    {
        all->line = ft_calloc(BUFFER_SIZE, sizeof(char));
        read(0, all->line, BUFFER_SIZE);
        if (all->line[0] == '\0' || all->line[0] == '\n')
        {
            checker_sort(all);
            the_end(&all->a, &all->b, &all->line, all);
            free(all);
        }
        else
            checker_pars_v(&all->a, &all->b, all->len, all->line);
        system("clear");
        print_all(all->a, all->b);
        free_arg(&(all->line));
    }
    if (all->line[0] == '\0' || all->line[0] == '\n')
    {
        checker_sort(all);
        the_end(&all->a, &all->b, &all->line, all);
        free(all);
    }
}