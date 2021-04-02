/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:07:59 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/02 18:06:19 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void add_back(t_stack **head,t_stack *new)
{
    t_stack *tmp;
    
    if (!head || !new)
        return;
    if (new)
    {
        tmp = *head;
        while (tmp->next)
                tmp = tmp->next;
        tmp->next = new;
        new->next = NULL;
        new->previous = tmp;
        }
    else
        *head = new;
}

t_stack *creat_stack(char *av,t_stack *A)
{
    A = malloc(sizeof(t_stack));
    
    A->number = ft_atoi(av);
    A->next = NULL;
    A->previous = NULL;
    return (A);
}

t_stack *put_in_list(char **av)
{
    t_stack *A;
    t_stack *tmp;
    int i;

    i = 1;
    A = malloc(sizeof(t_stack));
    while (av[i])
    {
        // puts(av[i]);
        tmp = creat_stack(av[i], tmp);
        add_back(&A, tmp);
        i++;
    }
    // free_stack(tmp);
    return (A);
}
