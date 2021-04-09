/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 13:06:00 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/09 17:21:07 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_pivot(t_stack *c)
{
    t_stack *result;
    int len;
    int m;
    int k;

    result = sort(dup_list(c));
    len = size_list(result);
    if (len <= 12)
        m = val_aprox(len / 2);
    else if (len > 12 && len < 500)
        m = val_aprox(len / 5);
    // else if (len >= 500)
    // m = val_aprox(len / 8);
    k = node_nbr(&result, m);
    return (k);
}

int check_under_pivot(t_stack *a, int pivot)
{
    while (a)
    {
        if (a->number <= pivot)
            return (1);
        a = a->next;
    }
    return (0);
}

int check_upper_pivot(t_stack *a, int pivot)
{
    while (a)
    {
        if (a->number == pivot)
            return (1);
        a = a->next;
    }
    return (0);
}

int get_index(t_stack *a, int pivot)
{
    int i;
    i = 1;

    while (a)
    {
        if (a->number <= pivot)
            return (i);
        a = a->next;
        i++;
    }
    return (-1);
}

int get_index_max(t_stack *a, int pivot)
{
    int i;
    i = 1;

    while (a)
    {
        if (a->number == pivot)
            return (i);
        a = a->next;
        i++;
    }
    return (-1);
}

int get_min(t_stack *a)
{
    int min = a->number;
    t_stack *tmp;
    tmp = a;
    while (a)
    {
        if (a->number < min)
            min = a->number;
        a = a->next;
    }
    return (min);
}

int get_max(t_stack *b)
{
    int max = b->number;
    t_stack *tmp;
    tmp = b;
    while (b)
    {
        if (b->number >= max)
            max = b->number;
        b = b->next;
    }
    b = tmp;
    return (max);
}

void le_vide_vider(t_stack **a, t_stack **b)
{
    while (*a)
    {
        switch_case(a, b, 1);
        // sleep(1);
    }

    while (*b)
    {
        switch_case(a, b, 4);
        // sleep(1);
    }
    // free(*a);
    // free_stack(a);
    // print_list(*a);
    // puts(ft_itoa());
    if (size_list(*b))
        switch_case(a, b, 6);
}

void algo(t_stack **a, t_stack **b, int len)
{
    t_stack *now;
    int index;
    int proximity;
    int m;
    int size = len;

    now = (*a);
    // print_list(*a);

    while (size >= len / 5)
    {
        m = get_pivot(((*a)));
        while (check_under_pivot((*a), m))
        {
            if ((*a)->number <= m)
            {
                switch_case(a, b, 1);
                size--;
            }
            else
            {
                index = get_index((*a), m);
                proximity = (size_list((*a)) / 2);
                if (proximity > index)
                    switch_case(a, b, 2);
                else
                    switch_case(a, b, 3);
            }
        }
    }
    size = size_list(*a);
    while (*a && !check_sort(a, size))
    {
        int min = get_min(*a);
        while (size_list(*a) && check_under_pivot((*a), min))
        {
            if ((*a)->number == min)
            {
                switch_case(a, b, 1);
                size--;
            }
            else
            {
                index = get_index((*a), min);
                proximity = (size_list((*a)) / 2);
                if (proximity > index)
                    switch_case(a, b, 2);
                else
                    switch_case(a, b, 3);
            }
        }
    }
    // while (*b)
    {
        int max = get_max(*b);
        while (check_upper_pivot((*b), max))
        {
            // max = get_max(*b);
            while (((*b)->number != max))
            {
                // puts(ft_itoa(size_list(*b)));
                // print_list(*b);
                sleep(1);
                printf("MAX: %d\n", max);
                index = get_index_max((*b), max);
                proximity = val_aprox((size_list((*b)) / 2));
                if (proximity > index && *b) //|| size < 30
                    switch_case(a, b, 5);
                else if (*b)
                {

                    switch_case(a, b, 6);
                    print_list(*b);
                }
            }
            puts("doasdksaopdksa");
            while (*b && (*b)->number == max)
            {
                switch_case(a, b, 4);
                max = get_max(*b);
            }
        }
    }
}
