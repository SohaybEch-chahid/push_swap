/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:50:34 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/14 15:12:49 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

/*
Accept optional + and -.
Reject floating-point numbers.
Reject alphabetic characters.
Detect overflow.
Support spaces, tabs and other whitespace.
Preserve the original input order.
*/

static int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	ft_parse_token(const char *s, size_t len, int *nb)
{
	size_t			i;
	int				sign;
	int				digit;
	unsigned long	value;
	unsigned long	limit;

	i = 0;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			sign = -1;
	if (i == len)
		return (0);
	limit = (unsigned long)INT_MAX + (sign == -1);
	value = 0;
	while (i < len)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		digit = s[i++] - '0';
		if (value > (limit - digit) / 10)
			return (0);
		value = value * 10 + digit;
	}
	if (sign == -1 && value == (unsigned long)INT_MAX + 1)
		*nb = INT_MIN;
	else
		*nb = (int)value * sign;
	return (1);
}

static int	ft_append_number(t_data *stack, t_stack ***tail, int nb)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node->value = nb;
	node->next = NULL;
	**tail = node;
	*tail = &node->next;
	stack->size_stack++;
	return (1);
}

int	ft_parse_numbers(t_data *stack, const char *str, t_stack ***tail)
{
	size_t	i;
	size_t	start;
	int		nb;
	int		count;

	if (!str || !str[0])
		return (0);
	i = 0;
	count = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
			i++;
		if (!str[i])
			break ;
		start = i;
		while (str[i] && !ft_isspace(str[i]))
			i++;
		if (!ft_parse_token(str + start, i - start, &nb))
			return (0);
		if (!ft_append_number(stack, tail, nb))
			return (0);
		count++;
	}
	return (count > 0);
}
