/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:50:30 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/14 15:19:11 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Libft/libft.h"
#include "../push_swap.h"

const char	*ft_get_strategy_selector(char *str, int *index)
{
	if (!str || !index)
		return ("--adaptive");
	if (ft_strncmp(str, "--simple", 9) == 0)
	{
		(*index)++;
		return ("--simple");
	}
	if (ft_strncmp(str, "--medium", 9) == 0)
	{
		(*index)++;
		return ("--medium");
	}
	if (ft_strncmp(str, "--complex", 10) == 0)
	{
		(*index)++;
		return ("--complex");
	}
	if (ft_strncmp(str, "--adaptive", 11) == 0)
	{
		(*index)++;
		return ("--adaptive");
	}
	return ("--adaptive");
}
