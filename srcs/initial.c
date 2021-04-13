/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:46:37 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/13 11:26:24 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_all *initial(int ac, char **av, t_all *all)
{
    if (!(all = (t_all *)malloc(sizeof(t_all))))
        exit(1);
    all->a = NULL;
    all->b = NULL;
    all->len = 0;
    all->line = NULL;
    return (all);
}
