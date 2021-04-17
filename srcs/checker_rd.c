/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:15:44 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/16 22:26:20 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void checker_pars_v(t_stack **a, t_stack **b, int len, char *line)
{
    if (!ft_strcmp(line, "sa\n") && size_list(*a) > 1)
        swap_stack(a);
    else if (!ft_strcmp(line, "ra\n") && size_list(*a) > 1)
        r_stack(a);
    else if (!ft_strcmp(line, "rra\n") && size_list(*a) > 1)
        rr_stack(a);
    else if (!ft_strcmp(line, "sb\n") && size_list(*b) > 1)
        swap_stack(b);
    else if (!ft_strcmp(line, "rb\n") && size_list(*b) > 1)
        r_stack(b);
    else if (!ft_strcmp(line, "rrb\n") && size_list(*b) > 1)
        rr_stack(b);
    else if (!ft_strcmp(line, "pb\n"))
        push_stack(a, b);
    else if (!ft_strcmp(line, "pa\n"))
        push_stack(b, a);
    else if (!ft_strcmp(line, "ss\n") && size_list(*b) > 1 && size_list(*a) > 1)
        ss(a, b);
    else if (!ft_strcmp(line, "rr\n") && size_list(*b) > 1 && size_list(*a) > 1)
        rr(a, b);
    else if (!ft_strcmp(line, "rrr\n") && size_list(*b) > 1 && size_list(*a) > 1)
        rrr(a, b);
    else if (line[0] != '\0')
    {
        ft_putstr_fd("Error\n", 1);
        exit(1);
    }
}

void checker_pars(t_stack **a, t_stack **b, int len, char *line)
{
    if (!ft_strcmp(line, "sa") && size_list(*a) > 1)
        swap_stack(a);
    else if (!ft_strcmp(line, "ra") && size_list(*a) > 1)
        r_stack(a);
    else if (!ft_strcmp(line, "rra") && size_list(*a) > 1)
        rr_stack(a);
    else if (!ft_strcmp(line, "sb") && size_list(*b) > 1)
        swap_stack(b);
    else if (!ft_strcmp(line, "rb") && size_list(*b) > 1)
        r_stack(b);
    else if (!ft_strcmp(line, "rrb") && size_list(*b) > 1)
        rr_stack(b);
    else if (!ft_strcmp(line, "pb"))
        push_stack(a, b);
    else if (!ft_strcmp(line, "pa"))
        push_stack(b, a);
    else if (!ft_strcmp(line, "ss") && size_list(*b) > 1 && size_list(*a) > 1)
        ss(a, b);
    else if (!ft_strcmp(line, "rr") && size_list(*b) > 1 && size_list(*a) > 1)
        rr(a, b);
    else if (!ft_strcmp(line, "rrr") && size_list(*b) > 1 && size_list(*a) > 1)
        rrr(a, b);
 
}

int ft_strlen(char *s1)
{
    int k;

    k = 0;
    while (s1[k])
        k++;
    return (k);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char *s3;
    char *str1;
    char *str2;
    unsigned int len;

    if (!s1 || !s2)
    {
        return (NULL);
    }
    str1 = (char *)s1;
    str2 = (char *)s2;
    len = 0;
    s3 = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
    if (s3 == NULL)
        return (NULL);
    while (*str1)
        s3[len++] = *(str1++);
    while (*str2)
        s3[len++] = *(str2++);
    s3[len] = '\0';
    return (s3);
}