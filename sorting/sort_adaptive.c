/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 20:43:23 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/19 14:13:54 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_sort_adaptive(t_data *data)
{
    int *arr;
    double disorder;

    if (!data || data->size_stack < 2)
        return;
    if (data->size_stack <= 5)
    {
        ft_sort_simple(data);
        return;
    }
    arr = ft_copy_stack_to_array(data);
    if (!arr)
        return;
    disorder = ft_disorder(arr, data->size_stack);
    free(arr);
    if (data->size_stack <= 100 && disorder <= 60.0)
        ft_sort_medium(data);
    else
        ft_sort_complex(data);
}
