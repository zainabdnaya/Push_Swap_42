/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:49:59 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/10 14:50:57 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER
#define CHECKER

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#define BUFFER 10

typedef struct s_stack{

    int number;
    struct s_stack *next;
    struct s_stack *previous;
} t_stack;

/**********************LIST*******************/
t_stack *put_in_list(char **av);
t_stack *creat_stack(char *av, t_stack *a);
t_stack *add_back(t_stack **head,t_stack *new,char *av);
t_stack *dup_list(t_stack *head);

void    add_back1(t_stack **head,t_stack *new);
void    add_front(t_stack **head, t_stack *new_node);
int     node_nbr(t_stack **head, int index);
/**********************TOOlS*******************/
int         ft_strcmp(const char *s1, const char *s2);
int         size_list(t_stack *a);
int         val_aprox(float m);
int         check_under_pivot(t_stack *a, int pivot);
int         check_upper_pivot(t_stack *a, int pivot);
int         get_min(t_stack *a);

long long   my_atoi(const char *str);
/**********************ERRORS*********************/
int         first_errors(int ac, char **av);
int         check_ascii(char **av);
/**********************FREE*********************/
void     free_arg(char **arg);
void     free_stack(t_stack **stack);
void     free_single_stack(t_stack **stack);
/********************** MOVES*******************/
void     swap_stack(t_stack **head);
void     r_stack(t_stack **head);
void     rr_stack(t_stack **head);
void     push_stack(t_stack **a, t_stack **b);
void     ss(t_stack **a,t_stack **b);
void     rrr(t_stack **a,t_stack **b);
void     rr(t_stack **a,t_stack **b);
/********************** Sorting *******************/
t_stack  *sort(t_stack *head);

void    sort_result(t_stack *a,int len);
void    algo(t_stack **a, t_stack **b, int len);
void    switch_case(t_stack **a, t_stack **b, int w);

int     check_sort(t_stack **a,int len);
int     get_pivot(t_stack *a);
int     node_nbr(t_stack **head, int index);
int     get_index(t_stack *a, int pivot);
int     get_index_max(t_stack *a, int pivot);
int     get_max(t_stack *b);

/********************** Test  *******************/

void le_vide_vider(t_stack **a, t_stack **b);
void print_all(t_stack *a, t_stack *b);
void print_list(t_stack *ptr);

#endif