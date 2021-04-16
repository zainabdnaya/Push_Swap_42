/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:38:54 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/16 15:33:04 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_all *all;
    int i;

    i = 0;
    if (ac < 2)
        exit(1);
    else
    {
        all = initial(ac, all);

        if (!ft_strcmp(av[1], "-v"))
        {
            all->print = 1;
            if (ac == 3)
                all->split = ft_split(av[2], ' ');
            else
                all->split = &av[2];
        }
        else
        {
            if (ac == 2)
                all->split = ft_split(av[1], ' ');
            else
                all->split = &av[1];
        }

        check_replicat(all->split);
        check_ascii(all->split);
        all->a = put_in_list(all, all->split);
        all->len = size_list(all->a);

        char **line;
        int i = 0;
        int j = 0;
        char *str;
        all->line = ft_calloc(BUFFER_SIZE, sizeof(char));
        while (read(0, all->line, BUFFER_SIZE))
        {
            if (str == NULL)
                str = ft_strdup(all->line);
            else
                str = ft_strjoin(str, all->line);
        }
        line = ft_split(str, '\n');
        free_arg(&all->line);
        while (line[i])
        {
            checker_pars(&all->a, &all->b, all->len, line[i]);
            if (all->print == 1)
            {
                system("clear");
                print_all(all->a, all->b);
            }
            if (!ft_strcmp(line[i], "\0"))
            {
                if (check_sort(&all->a, all->len) == 1)
                    ft_putstr_fd("OK\n", 1);
                else
                    ft_putstr_fd("KO\n", 1);
            }
            i++;
        }
        if (check_sort(&all->a, all->len) == 1)
            ft_putstr_fd("OK\n", 1);
        else
            ft_putstr_fd("KO\n", 1);
    }
}
