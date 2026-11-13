/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:53:04 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/13 10:29:26 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
    int             value;
    struct s_stack  *next;
}   t_stack;

typedef struct s_data
{
    t_stack *stack;
    int     size_stack;
}   t_data;

/* Stack utilities */
void    ft_push(t_data **top, int value);
int     ft_pop(t_data **top, int *value);
void    ft_free_stack(t_data **top);
void    ft_display_stack(t_data *top);
t_data	*ft_create_stack(int argc, char **argv);

/* Operations */
void    ft_pa(t_data *stack_a, t_data *stack_b);
void    ft_pb(t_data *stack_a, t_data *stack_b);
void    ft_sa(t_data *stack_a);
void    ft_sb(t_data *stack_b);
void    ft_ss(t_data *stack_a, t_data *stack_b);
void    ft_ra(t_data *stack_a);
void    ft_rb(t_data *stack_b);
void    ft_rr(t_data *stack_a, t_data *stack_b);
void    ft_rra(t_data *stack_a);
void    ft_rrb(t_data *stack_b);
void    ft_rrr(t_data *stack_a, t_data *stack_b);

#endif
