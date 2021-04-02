/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:38:54 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/02 18:10:47 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void print_list(t_stack *ptr)
{
    printf("\n -------Printing list Start------- \n");
    while (ptr != NULL)
    {
        printf("[%d]\n", ptr->number);
        printf("↑↓\n");
        ptr = ptr->next;
    }
    printf("\n -------Printing list End------- \n");

    return;
}

int main(int ac, char **av)
{
    t_stack A;

    if (first_errors(ac, av) == 1)
    {
        A = *put_in_list(av);
        print_list(&A);
    }
}