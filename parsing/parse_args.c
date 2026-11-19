/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:50:30 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/18 23:12:58 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Libft/libft.h"
#include "../push_swap.h"

static void	ft_init_options(t_options *options)
{
	options->simple = 0;
	options->medium = 0;
	options->complex = 0;
	options->adaptive = 1;
}

int	ft_is_option(char *arg)
{
	if (!arg)
		return (0);
	if (!ft_strncmp(arg, "--simple", 9))
		return (1);
	if (!ft_strncmp(arg, "--medium", 9))
		return (1);
	if (!ft_strncmp(arg, "--complex", 9))
		return (1);
	if (!ft_strncmp(arg, "--adaptive", 11))
		return (1);
	return (0);
}

static int	ft_set_option(char *arg, t_options *options)
{
	if (!ft_strncmp(arg, "--simple", 9))
		options->simple = 1;
	else if (!ft_strncmp(arg, "--medium", 9))
		options->medium = 1;
	else if (!ft_strncmp(arg, "--complex", 9))
		options->complex = 1;
	else if (!ft_strncmp(arg, "--adaptive", 11))
		options->adaptive = 1;
	else
		return (0);
	return (1);
}

int	ft_parse_options(int ac, char **av, t_options *options)
{
	int	i;
	int	count;

	ft_init_options(options);
	i = 1;
	count = 0;
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1] == '-')
		{
			if (!ft_is_option(av[i]))
				return (0);
			if (++count > 1)
				return (0);
			options->adaptive = 0;
			if (!ft_set_option(av[i], options))
				return (0);
		}
		i++;
	}
	return (1);
}
