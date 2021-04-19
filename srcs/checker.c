/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:38:54 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/19 21:20:19 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **normal(t_all *all, int ac, char **av)
{
    if (ac == 2)
        all->split = ft_split(av[1], ' ');
    else
        all->split = &av[1];
    return (all->split);
}

int condition(t_stack **a, t_stack **b, char *line)
{
    if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "ra"))
        return (1);
    if (!ft_strcmp(line, "rra") || !ft_strcmp(line, "sb"))
        return (1);
    if (!ft_strcmp(line, "rb") || !ft_strcmp(line, "rrb"))
        return (1);
    if (!ft_strcmp(line, "pb") || !ft_strcmp(line, "pa"))
        return (1);
    if (!ft_strcmp(line, "pa") || !ft_strcmp(line, "ss"))
        return (1);
    if (!ft_strcmp(line, "rrr") || !ft_strcmp(line, "rr"))
        return (1);
    else
        return (0);
}

void checker(t_all *all, char *str, char **line)
{
    int i;

    i = 0;
    char *tmp;

    all->line = ft_calloc(BUFFER_SIZE, sizeof(char));
    while (read(0, all->line, BUFFER_SIZE))
    {
        tmp = str;
        if (str == NULL)
            str = ft_strdup(all->line);
        else
            str = ft_strjoin(str, all->line);
        if (tmp)
        {
            free(tmp);
            tmp = NULL;
        }
    }
    if (!ft_strcmp(all->line, "\0"))
        checker_sort(all);
    free_arg(&all->line);
    line = ft_split(str, '\n');
    free_arg(&str);
    while (line[i])
    {
        if (condition(&all->a, &all->b, line[i]) == 1)
            checker_pars(&all->a, &all->b, all->len, line[i]);
        else
        {
            ft_free_split(line);
            free_stack(&all->a);
            free_stack(&all->b);
            free(all);
            all = NULL;
            ft_putstr_fd("Error\n", 1);
            exit(1);
        }
        i++;
    }
    ft_free_split(line);
    checker_sort(all);
}

int main(int ac, char **av)
{
    t_all *all;
    char **line;
    char *str;

    str = NULL;
    line = NULL;
    if (ac < 2)
        exit(1);
    else
    {
        all = initial(ac, all);
        if (!ft_strcmp(av[1], "-v"))
            option_v(all, ac, av);
        else
        {
            all->split = normal(all, ac, av);
            all = fill_in(all);
            checker(all, str, line);
        }
    }
}
