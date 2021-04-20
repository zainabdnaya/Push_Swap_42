/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:59:35 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/20 16:07:40 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_replicat(char **av)
{
    int i;
    int j;
    char *replica;

    i = 0;
    j = 0;
    if (!av[i])
    {
        ft_putstr_fd("Error: fill stack A with Integers!", 2);
        exit(1);
    }
    while (av[i])
    {
        replica = ft_strdup(av[i]);
        j = 0;
        while (av[j])
        {
            if (j == i)
                j++;
            else if (ft_strcmp(replica, av[j]) == 0)
            {
                ft_putstr_fd("Error:\n", 2);
                free_arg(&replica);
                exit(1);
            }
            else
                j++;
        }
        free_arg(&replica);
        i++;
    }
}

int check_ascii(char **av)
{
    int i;
    int j;

    i = 0;
    while (av[i])
    {
        j = 0;
        while (av[i][j])
        {
            if (ft_isalpha(av[i][j]) == 1 || av[i][j] == '.' 
            || ((av[i][j]) == '-' && (av[i][j + 1]) == '\0' ) 
            || ((av[i][j]) == '+' && (av[i][j + 1]) == '\0'))
            {
                ft_putstr_fd("Error:\n", 2);
                exit(1);
            }

            j++;
        }
        i++;
    }
    return (1);
}
