/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:38:54 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/17 17:33:44 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_all *fill_in(t_all *all)
{
    t_stack *new;

    check_replicat(all->split);
    check_ascii(all->split);
    all->a = put_in_list(all, all->split,new);
    all->len = size_list(all->a);
    free_stack(&new);
    return (all);
}
// void checker_sort(t_all *all)
// {
//     if (check_sort(&all->a, all->len) == 1)
//         ft_putstr_fd("OK\n", 1);
//     else
//         ft_putstr_fd("KO\n", 1);
// }

// void option_v(t_all *all, int ac, char **av)
// {
//     if (ac == 3)
//         all->split = ft_split(av[2], ' ');
//     else
//         all->split = &av[2];
//     all = fill_in(all);
//     while (1)
//     {
//         all->line = ft_calloc(BUFFER_SIZE, sizeof(char));
//         read(0, all->line, BUFFER_SIZE);
//         checker_pars_v(&all->a, &all->b, all->len, all->line);
//         system("clear");
//         print_all(all->a, all->b);
//         free_arg(&(all->line));
//     }
//     if (all->line[0] == '\0' || all->line[0] == '\n')
//         checker_sort(all);
// }

// char **normal(t_all *all, int ac, char **av)
// {
//     if (ac == 2)
//         all->split = ft_split(av[1], ' ');
//     else
//         all->split = &av[1];
//     return (all->split);
// }

// int condition(t_stack **a, t_stack **b, char *line)
// {
//     if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "ra"))
//         return (1);
//     if (!ft_strcmp(line, "rra") || !ft_strcmp(line, "sb"))
//         return (1);
//     if (!ft_strcmp(line, "rb") || !ft_strcmp(line, "rrb"))
//         return (1);
//     if (!ft_strcmp(line, "pb") || !ft_strcmp(line, "pa"))
//         return (1);
//     if (!ft_strcmp(line, "pa") || !ft_strcmp(line, "ss"))
//         return (1);
//     if (!ft_strcmp(line, "rrr") || !ft_strcmp(line, "rr"))
//         return (1);
//     else
//         return (0);
// }
// void checker(t_all *all, char *str, char **line)
// {
//     int i;

//     i = 0;
//     all->line = ft_calloc(BUFFER_SIZE, sizeof(char));
//     while (read(0, all->line, BUFFER_SIZE))
//     {
//         if (str == NULL)
//             str = ft_strdup(all->line);
//         else
//             str = ft_strjoin(str, all->line);
//     }
//     if (!ft_strcmp(all->line, "\0"))
//         checker_sort(all);
//     line = ft_split(str, '\n');
//     while (line[i])
//     {
//         if (condition(&all->a, &all->b, line[i]) == 1)
//             checker_pars(&all->a, &all->b, all->len, line[i]);
//         else
//         {
//             free_arg(line);
//             free_arg(&str);
//             ft_free_split(line);
//             the_end(&all->a, &all->b, &all->line, all);
//             ft_putstr_fd("Error\n", 1);
//             exit(1);
//         }
//         i++;
//     }
//     checker_sort(all);
//     free_arg(&str);
//     ft_free_split(line);
//     the_end(&all->a, &all->b, &all->line, all);
// }

int main(int ac, char **av)
{
    t_all *all;
    char **line;
    char *str;
    int p;
    p = 0;

    str = NULL;
    line = NULL;
    if (ac < 2)
        exit(1);
    else
    {
        all = initial(ac, all);
        // if (!ft_strcmp(av[1], "-v"))
        //     option_v(all, ac, av);
        // else
        // {
        //     all->split = normal(all, ac, av);
        //     all = fill_in(all);
        //     checker(all, str, line);
        // }
        the_end(&all->a, &all->b, &all->line, all);
        free(all);
        all = NULL;
    }
}
