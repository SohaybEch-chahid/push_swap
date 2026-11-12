/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:53:04 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/12 05:04:33 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

t_stack				*ft_create_stack(int argc, char **argv);
int					is_empty(t_stack *top);
void				ft_push(t_stack **top, int value);
int					ft_pop(t_stack **top, int *value);
void				ft_display_stack(t_stack *top);
void				ft_free_stack(t_stack **top);

#endif
