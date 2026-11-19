/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 20:42:21 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/18 23:27:02 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    ft_sort_complex(t_data *stack_a){
	t_data	*stack_b;

	stack_b = ft_create_empty_stack();
	if (!stack_b)
		return ;
	ft_sort_radix(stack_a, stack_b);
	ft_free_stack(stack_b);
	free(stack_b);
}
