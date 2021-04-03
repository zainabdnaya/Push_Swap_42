/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:38:54 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/03 13:27:32 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void print_list(t_stack *ptr)
{
    // printf(" -------Printing list Start------- \n");
    while (ptr != NULL)
    {
        printf("[%d]\n", ptr->number);
        printf("↑↓\n");
        ptr = ptr->next;
    }
    // printf(" -------Printing list End------- \n");

    return;
}

int main(int ac, char **av)
{
    t_stack A;

    if (first_errors(ac, av) && check_ascii(av) )
    {
        puts("---------Printing list Start--------");
        A = *put_in_list(av);
        print_list(&A);
        // puts("------- sa : Swap 2 first element---");
        // A = *swap_stack(&A);
        // print_list(&A);
        puts("----------- Roate stack ------------");
        A = *rotate_stack(&A);
        print_list(&A);

    }
}