/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:46:37 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/20 03:44:38 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_all *initial(t_all *all)
{
    if (!(all = (t_all *)malloc(sizeof(t_all))))
        exit(1);
    all->a = NULL;
    all->b = NULL;
    all->len = 0;
    all->line = NULL;
    all->split = NULL;
    all->print = 0;
    all->color = 0;
    return (all);
}
