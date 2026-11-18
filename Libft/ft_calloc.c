/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:58:15 by sech-cha          #+#    #+#             */
/*   Updated: 2026/10/19 14:58:16 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*arr;

	if (nmemb == 0 || size == 0)
	{
		arr = malloc(0);
		if (arr == NULL)
			return (NULL);
		return (arr);
	}
	if (nmemb > (size_t)-1 / size)
		return (NULL);
	total_size = nmemb * size;
	arr = malloc(total_size);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, total_size);
	return (arr);
}
