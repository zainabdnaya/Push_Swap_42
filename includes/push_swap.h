/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:49:59 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/19 06:56:18 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER
#define CHECKER

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 2048
#define RED "\e[0;31msa"
#define GRN "\e[0;32mra"
#define YEL "\e[0;33mrra"
#define BLU "\e[0;34mpa"
#define MAG "\e[0;35mrb"
#define CYN "\e[0;36mrrb"
#define WHT "\e[0;37mpb"
#define BHBLK "\e[1;90msb"
#define YELHB "\e[0;103mss"
#define CYNHB "\e[0;106mrr"
#define GRNHB "\e[0;102mrrr"

typedef struct s_stack
{
    int number;
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
long long my_atoi(const char *str);

void add_back(t_stack **head, t_stack *new, char *av);
void add_back1(t_stack **head, t_stack *new, int k);
void add_front(t_stack **head, t_stack *new_node);
void checker_sort(t_all *all);
void check_replicat(char **av);
void swap_stack(t_stack **head);
void r_stack(t_stack **head, t_stack *tmp);
void rr_stack(t_stack **head, t_stack *tmp);
void push_stack(t_stack **a, t_stack **b, t_stack *new);
void ss(t_stack **a, t_stack **b);
void rrr(t_stack **a, t_stack **b);
void rr(t_stack **a, t_stack **b);
void sort_result(t_stack *a, int len);
void algo(t_stack **a, t_stack **b, int len);
void switch_case(t_stack **a, t_stack **b, int w);
void algo_1(t_stack **a, t_stack **b, int len);
void algo_min(t_stack **a, t_stack **b, int len);
void checker_pars(t_stack **a, t_stack **b, int len, char *line);
void sort_a_3(t_stack **a, t_stack **b, int len);
void sort_min(t_stack **a, t_stack **b, int len);
void le_vide_vider(t_stack **a, t_stack **b);
void print_all(t_stack *a, t_stack *b);
void print_list(t_stack *ptr);
void switch_case_color(t_stack **a, t_stack **b, int w);
void sort_a_3_c(t_stack **a, t_stack **b, int len);
void sort_min_c(t_stack **a, t_stack **b, int len);
void algo_1_c(t_stack **a, t_stack **b, int len);
void algo_c(t_stack **a, t_stack **b, int len);
void s_c_display(t_stack **a, t_stack **b, int w);
void algo_1_d(t_stack **a, t_stack **b, int len);
void sort_min_d(t_stack **a, t_stack **b, int len);
void algo_d(t_stack **a, t_stack **b, int len);
void swap_(t_all *all, int ac, char **av);
void swap_c(t_all *all, int ac, char **av);
void swap_sh(t_all *all, int ac, char **av);
void ft_putnbr_fd(int n, int fd);
void ft_putstr_fd(char *s, int fd);
void ft_putchar_fd(char c, int fd);
void ft_putendl_fd(char *s, int fd);
void *ft_calloc(size_t count, size_t size);
void checker_pars_v(t_stack **a, t_stack **b, int len, char *line);
void display(t_stack *a, t_stack *b);
void option_v(t_all *all, int ac, char **av);
void free_arg(char **arg);
void free_stack(t_stack **stack);
void free_single_stack(t_stack **stack);
void the_end(t_stack **a, t_stack **b, char **line, t_all *all);
void ft_free_split(char **split);

char **ft_split(char const *s, char c);
char *ft_strdup(const char *src);
char *ft_strjoin(char const *s1, char const *s2);

int ft_isalpha(int c);
int check_sort(t_stack **a, int len);
int get_pivot(t_stack *a);
int node_nbr(t_stack **head, int index);
int get_index(t_stack *a, int pivot);
int get_index_max(t_stack *a, int pivot);
int get_max(t_stack *b);
int check_ascii(char **av);
int node_nbr(t_stack **head, int index);
int ft_strcmp(const char *s1, const char *s2);
int size_list(t_stack *a);
int val_aprox(float m);
int check_under_pivot(t_stack *a, int pivot);
int check_upper_pivot(t_stack *a, int pivot);
int get_min(t_stack *a);

t_stack *bottom(t_stack *a);
t_stack *sort(t_stack *head);
t_stack *put_in_list(t_all *all, char **av, t_stack *new);
t_stack *creat_stack(char *av, t_stack *a);
t_stack *dup_list(t_stack *head);

t_all *fill_in(t_all *all);
t_all *initial(int ac, t_all *all);


#endif