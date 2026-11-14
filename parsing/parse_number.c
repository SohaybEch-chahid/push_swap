/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:50:34 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/14 14:23:28 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Libft/libft.h"
#include "../push_swap.h"

t_data	*ft_parse_numbers(t_data *stack, char *str)
{
	int	nb;

	// implment stack hhh
	if (!str || !str[0])
		return (NULL);
	while (str)
	{
		nb = ft_atoi(str);
		ft_push(stack, nb);
	}
	return (stack);
}
