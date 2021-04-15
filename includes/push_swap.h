/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:49:59 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/15 01:17:06 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER
#define CHECKER

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "./get_next_line.h"
#define BUFFER_SIZE 2048
#define RED "\e[0;31msa"
#define GRN "\e[0;32mra"
#define YEL "\e[0;33mrra"
#define BLU "\e[0;34mpa"
#define MAG "\e[0;35mrb"
#define CYN "\e[0;36mrrb"
#define WHT "\e[0;37mpb"
#define BHBLK "\e[1;90msb"



typedef struct s_stack
{
    int number;
    int color;
    struct s_stack *next;
    struct s_stack *previous;
} t_stack;

typedef struct s_all
{
    char *line;
    char **split;
    int len;
    int print;
    int color;
    t_stack *a;
    t_stack *b;
} t_all;

/**********************LIST*******************/
t_stack *put_in_list(t_all *all, char **av);
t_stack *creat_stack(char *av, t_stack *a);
t_stack *dup_list(t_stack *head);
t_all   *initial(int ac,  t_all *all);

void add_back(t_stack **head, t_stack *new, char *av);
void add_back1(t_stack **head, t_stack *new, int k);
void add_front(t_stack **head, t_stack *new_node);
int node_nbr(t_stack **head, int index);
/**********************TOOlS*******************/
int ft_strcmp(const char *s1, const char *s2);
int size_list(t_stack *a);
int val_aprox(float m);
int check_under_pivot(t_stack *a, int pivot);
int check_upper_pivot(t_stack *a, int pivot);
int get_min(t_stack *a);

long long my_atoi(const char *str);
/**********************ERRORS*********************/
void check_replicat(char **av);
int check_ascii(char **av);
/**********************FREE*********************/
void free_arg(char **arg);
void free_stack(t_stack **stack);
void free_single_stack(t_stack **stack);
void the_end(t_stack **a, t_stack **b, char **line,t_all *all);
/********************** MOVES*******************/
void swap_stack(t_stack **head);
void r_stack(t_stack **head);
void rr_stack(t_stack **head);
void push_stack(t_stack **a, t_stack **b);
void ss(t_stack **a, t_stack **b);
void rrr(t_stack **a, t_stack **b);
void rr(t_stack **a, t_stack **b);
/********************** Sorting *******************/
t_stack *sort(t_stack *head);

void sort_result(t_stack *a, int len);
void algo(t_stack **a, t_stack **b, int len);
void switch_case(t_stack **a, t_stack **b, int w);
void algo_1(t_stack **a, t_stack **b, int len);
int check_sort(t_stack **a, int len);
int get_pivot(t_stack *a);
int node_nbr(t_stack **head, int index);
int get_index(t_stack *a, int pivot);
int get_index_max(t_stack *a, int pivot);
int get_max(t_stack *b);
void algo_min(t_stack **a, t_stack **b, int len);
void checker_pars(t_stack **a, t_stack **b, int len, char *line);
void sort_a_3(t_stack **a, t_stack **b, int len);
void sort_min(t_stack **a, t_stack **b, int len);

void le_vide_vider(t_stack **a, t_stack **b);
void print_all(t_stack *a, t_stack *b);
void print_list(t_stack *ptr);
t_stack *bottom(t_stack *a);
/********************** color  *******************/
void switch_case_color(t_stack **a, t_stack **b, int w);
void sort_a_3_c(t_stack **a, t_stack **b, int len);
void sort_min_c(t_stack **a, t_stack **b, int len);
void algo_1_c(t_stack **a, t_stack **b, int len);
void algo_c(t_stack **a, t_stack **b, int len);
#endif