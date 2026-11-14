/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:50:30 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/14 14:24:30 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Libft/libft.h"
#include "../push_swap.h"

char	*ft_get_strategy_selector(char *str, int *index)
{
	char	*selector;

	if ((ft_strncmp(str, "--simple", 8) == 0)
		|| (ft_strncmp(str, "--medium", 8) == 0)
		|| (ft_strncmp(str, "--complex", 9) == 0)
		|| (ft_strncmp(str, "--adaptive", 8) == 0))
	{
		selector = str;
		(*index)++;
	}
	else
		selector = "--adaptive";
    return (selector);
}
