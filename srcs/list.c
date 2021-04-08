/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:07:59 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/08 10:39:03 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *add_back(t_stack **head, t_stack *new, char *av)
{
    t_stack *tmp;

    new = (t_stack *)malloc(sizeof(t_stack));
    new->number = my_atoi(av);
    if (new->number > 32767 || new->number < -32768)
    {
        ft_putstr_fd("Error:\n", 2);
        exit(1);
    }
    new->next = NULL;
    new->previous = NULL;
    if (*head == NULL)
        *head = new;
    else
    {
        tmp = *head;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
        new->previous = tmp;
    }
    return (*head);
}

void add_back1(t_stack **head, t_stack *new)
{
    t_stack *tmp;

    if (!head)
        *head = new;
    else
    {
        tmp = *head;

        if (new)
        {
            while (tmp->next)
                tmp = tmp->next;
            // puts("*************");
            tmp->next = new;
            new->previous = tmp;
        }
    }
}

t_stack *add_front(t_stack **head, t_stack *new_node)
{
    new_node->next = (*head);
    new_node->previous = NULL;

    if ((*head) != NULL)
        (*head)->previous = new_node;
    (*head) = new_node;
    return (*head);
}

t_stack *put_in_list(char **av)
{
    t_stack *A;
    t_stack *tmp;
    char *str;
    int i;

    i = 1;
    A = (t_stack *)malloc(sizeof(t_stack));
    A = NULL;
    tmp = NULL;
    str = NULL;
    while (av[i])
    {
        str = ft_strdup(av[i]);
        add_back(&A, tmp, str);
        // free_stack(tmp);
        // free_arg(&str);
        i++;
    }
    return (A);
}
