/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:49:48 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/14 14:36:54 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Libft/libft.h"
#include "../push_swap.h"

t_data	*ft_create_stack(int ac, char **av)
{
	int		i;
	int		j;
	int		nb;
	t_data	*stack;
	char	*selector;
	char	**res;

	selector = NULL;
	stack = malloc(sizeof(t_data));
    if (!stack)
        return NULL;
	stack->stack = NULL;
	stack->size_stack = 0;
	i = 1;
	while (i < ac)
	{
        j = 0;
		res = ft_split(av[i], ' ');
		if (!res)
			return (NULL);
		// check strategy a lmol7id
		// had l party gha n7tha f parse args function
		if (!selector && i < 2)
			selector = ft_get_strategy_selector(res[j], &j);
		// implment stack hhh
        while (res[j]) {
		    stack = ft_parse_numbers(stack, res[j]);
            j++;
        }
        j = 0;
        while (res[j])
            free(res[j++]);
        free(res);
		i++;
	}
	if (!ft_check_duplicates(stack))
		return (NULL);
	return (stack);
}
