/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:49:48 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/13 18:40:01 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../../Libft/libft.h"

t_data	*ft_create_stack(int ac, char **av)
{
	int		i;
	int		j;
	int		nb;
	t_data	*stack;
	char	*selector = NULL;
	char	**res;

	stack = malloc(sizeof(t_data));
	stack->stack = NULL;
	stack->size_stack = 0;
	i = 1;
	while (i < ac)
	{
		res = ft_split(av[i], ' ');
		if (!res)
			return (NULL);
		// check strategy a lmol7id
        // had l party gha n7tha f parse args function
        if (!selector)
            selector = ft_get_strategy_selector(res[j], &j);

		// implment stack hhh
        stack = ft_parse_numbers(stack, res[j], &j);
        i++;
	}
    if (!ft_check_duplicates(stack))
        return NULL;
	return (stack);
}
