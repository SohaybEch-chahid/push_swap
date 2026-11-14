/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:50:24 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/14 14:19:46 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Libft/libft.h"
#include "../push_swap.h"

int	ft_get_lst_max(t_stack *head)
{
	int	i;
	int	max;
    int min;

	i = 0;
	max = head->value;
    min = head->value;
	while (head)
	{
		if (head->value > max)
			max = head->value;
		if (head->value < min)
			min = head->value;
		head = head->next;
	}
	return (max - min);
}

int	ft_is_duplicates(t_stack *top, int max)
{
	char	*freq_arr;
	int		i;

	freq_arr = ft_calloc(max, 1); // to initialized with 0
	if (!freq_arr)
		return (0);
	while (top)
	{
		freq_arr[top->value]++;
		top = top->next;
	}
	i = 0;
	while (i < max)
	{
		if (freq_arr[i] > 1) // have dup
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_duplicates(t_data *data)
{
	int	max;
	int	check;

	if (data->size_stack < 1)
		return (0);
	max = ft_get_lst_max(data->stack);
	return (ft_is_duplicates(data->stack, max));
}
