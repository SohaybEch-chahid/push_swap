/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:57:22 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/18 23:15:31 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data		*stack;
	t_options	options;

	if (!ft_parse_options(ac, av, &options))
		return (write(2, "Error\n", 6), 1);
	stack = ft_create_stack(ac, av);
	if (!stack)
		return (write(2, "Error\n", 6), 1);
	ft_sort(stack, &options);
	ft_free_stack(stack);
	free(stack);
	return (0);
}
