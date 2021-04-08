/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:49:59 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/08 12:06:19 by zdnaya           ###   ########.fr       */
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
t_stack *creat_stack(char *av, t_stack *A);
t_stack *add_back(t_stack **head,t_stack *new,char *av);
void    add_back1(t_stack **head,t_stack *new);
t_stack *add_front(t_stack **head, t_stack *new_node);

void print_all(t_stack *A, t_stack *B);
void print_list(t_stack *ptr);
/**********************TOOlS*******************/
int ft_strcmp(const char *s1, const char *s2);
int size_list(t_stack *A);
long long my_atoi(const char *str);
/**********************ERRORS*********************/
int first_errors(int ac, char **av);
int check_ascii(char **av);
/**********************FREE*********************/
void free_arg(char **arg);
void free_stack(t_stack **stack);
void free_single_stack(t_stack **stack);
/********************** MOVES*******************/
void     swap_stack(t_stack **head);
void     r_stack(t_stack **head);
void     rr_stack(t_stack **head);
void     push_stack(t_stack **A, t_stack **B);
void     ss(t_stack **A,t_stack **B);
void     rrr(t_stack **A,t_stack **B);
void     rr(t_stack **A,t_stack **B);
/********************** Sorting *******************/
int     avreage(t_stack *A);
void    sort(t_stack *head);
int     check_sort(t_stack **A,int len);
void     sort_result(t_stack *A,int len);

// void first(t_stack **A, t_stack **B);

#endif