/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:06:51 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/20 14:41:22 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void display(t_stack *a, t_stack *b)
{
    int len;

    len = size_list(a);
    system("clear");
    ft_putstr_fd("\n\t-------------------------------\n", 1);
    ft_putstr_fd("        \tA         \tB         ", 1);
    ft_putstr_fd("\n\t-------------------------------\n", 1);
    while ((a) || (b))
    {
        ft_putstr_fd("\t        ", 1);
        if ((a))
            ft_putnbr_fd((a)->number, 1);
        else
            ft_putstr_fd("   ", 1);
        ft_putstr_fd("\t        ", 1);
        if (b)
            ft_putnbr_fd((b)->number, 1);
        else
            ft_putstr_fd("   ", 1);
        ft_putstr_fd("\n", 1);
        if (a)
            (a) = (a)->next;
        if (b)
            b = (b)->next;
    }
    if (len <= 10)
        usleep(1000000);
    else if (len > 10 && len <= 100)
        usleep(100000);
    else if (len > 100)
        usleep(10000);
}

void print_list(t_stack *ptr)
{
    t_stack *tmp;
    tmp = ptr;
    char *s1;
    char *s2;

    s1 = "A";
    s2 = "B";

    while (ptr)
    {
        ft_putstr_fd("{", 1);
        ft_putnbr_fd(ptr->number, 1);
        ft_putstr_fd("}⇄", 1);
        ptr = ptr->next;
    }
    ft_putstr_fd("\n", 1);
    ptr = tmp;
    return;
}

void print_all(t_stack *a, t_stack *b)
{
    if (a)
    {
        ft_putstr_fd("a:", 1);
        print_list(a);
    }
    else if (a == NULL)
        ft_putstr_fd("a is empty \n", 1);
    if (b)
    {
        ft_putstr_fd("b:", 1);
        print_list(b);
    }
    else if (b == NULL)
        ft_putstr_fd("b is empty \n", 1);
}