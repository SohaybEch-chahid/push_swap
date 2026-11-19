/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 20:26:57 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/18 20:30:49 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_count_inversions(int *arr, int size)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

double	ft_disorder(int *arr, int size)
{
	int	inversions;
	double	max_inversions;

	if (size < 2)
		return (0.0);
	inversions = ft_count_inversions(arr, size);
	max_inversions = (double)size * (size - 1) / 2;
	return (inversions / max_inversions * 100.0);
}
