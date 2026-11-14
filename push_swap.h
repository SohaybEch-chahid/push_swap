/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:53:04 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/14 15:19:40 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

typedef struct s_data
{
	t_stack			*stack;
	int				size_stack;
}					t_data;

/* Stack utilities */
void				ft_push(t_data *top, int value);
int					ft_pop(t_data *top, int *value);
void				ft_free_stack(t_data *top);
void				ft_display_stack(t_data *top);
t_data				*ft_create_stack(int argc, char **argv);

/* Operations */
void				ft_pa(t_data *stack_A, t_data *stack_B);
void				ft_pb(t_data *stack_A, t_data *stack_B);
void				ft_sa(t_data *stack_A);
void				ft_sb(t_data *stack_B);
void				ft_ss(t_data *stack_A, t_data *stack_B);
void				ft_ra(t_data *stack_A);
void				ft_rb(t_data *stack_B);
void				ft_rr(t_data *stack_A, t_data *stack_B);
void				ft_rra(t_data *stack_A);
void				ft_rrb(t_data *stack_B);
void				ft_rrr(t_data *stack_A, t_data *stack_B);

/* Parsing part */
const char	*ft_get_strategy_selector(char *str, int *index);
int					ft_parse_numbers(t_data *stack, const char *str,
						t_stack ***tail);
int					ft_check_duplicates(t_data *data);

#endif
