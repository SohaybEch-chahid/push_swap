/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:57:22 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/13 15:18:02 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
    t_data *stack_A;

	stack_A = NULL;
	stack_A = ft_create_stack(ac, av);
	ft_display_stack(stack_A);
	ft_free_stack(stack_A);
	return (0);
}
