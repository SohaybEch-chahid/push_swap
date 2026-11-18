/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 15:06:18 by sech-cha          #+#    #+#             */
/*   Updated: 2026/10/27 10:12:56 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_len(int n)
{
	int		len;
	long	nb;

	if (n == 0)
		return (1);
	nb = (long)n;
	len = 0;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

static char	*ft_insert_nb(char *res, int n, int len)
{
	int		i;
	long	nb;

	res[len] = '\0';
	if (n == 0)
	{
		res[0] = '0';
		return (res);
	}
	nb = (long)n;
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	i = len - 1;
	while (nb > 0)
	{
		res[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		str_len;

	str_len = ft_nb_len(n);
	res = malloc(str_len + 1);
	if (!res)
		return (NULL);
	res = ft_insert_nb(res, n, str_len);
	return (res);
}
