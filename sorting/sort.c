/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 20:28:20 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/18 20:34:55 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort(t_data *data, t_options *options)
{
	if (options->simple)
		ft_sort_simple(data);
	else if (options->medium)
		ft_sort_medium(data);
	else if (options->complex)
		ft_sort_complex(data);
	else
		ft_sort_adaptive(data);
}
