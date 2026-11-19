#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
    int value;
    int index;
    struct s_stack *next;
} t_stack;

typedef struct s_data
{
    t_stack *stack;
    int size_stack;
} t_data;

typedef struct s_options
{
    int simple;
    int medium;
    int complex;
    int adaptive;
} t_options;

void ft_push(t_data *top, int value);
int ft_pop(t_data *top, int *value);
void ft_free_stack(t_data *top);
void ft_display_stack(t_data *top);
t_data *ft_create_stack(int argc, char **argv);
t_data *ft_create_empty_stack(void);

void ft_pa(t_data *a, t_data *b);
void ft_pb(t_data *a, t_data *b);
void ft_sa(t_data *a);
void ft_sb(t_data *b);
void ft_ss(t_data *a, t_data *b);
void ft_ra(t_data *a);
void ft_rb(t_data *b);
void ft_rr(t_data *a, t_data *b);
void ft_rra(t_data *a);
void ft_rrb(t_data *b);
void ft_rrr(t_data *a, t_data *b);

int ft_parse_options(int ac, char **av, t_options *options);
int ft_is_option(char *arg);
int ft_parse_numbers(t_data *stack, const char *str, t_stack ***tail);
int ft_check_duplicates(t_data *data);

void ft_sort(t_data *data, t_options *options);
void ft_sort_selection(t_data *a, t_data *b);
void ft_sort_chunk(t_data *a, t_data *b);
void ft_sort_radix(t_data *a, t_data *b);
void ft_sort_simple(t_data *a);
void ft_sort_medium(t_data *a);
void ft_sort_complex(t_data *a);
void ft_sort_adaptive(t_data *data);
int ft_index_stack(t_data *stack);
int *ft_copy_stack_to_array(t_data *stack);

int ft_count_inversions(int *arr, int size);
double ft_disorder(int *arr, int size);

#endif
