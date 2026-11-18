/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 15:14:54 by sech-cha          #+#    #+#             */
/*   Updated: 2026/10/27 10:15:33 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	len;
	t_list			*current;

	len = 0;
	if (!lst)
		return (len);
	current = lst;
	while (current)
	{
		len++;
		current = current->next;
	}
	return (len);
}
