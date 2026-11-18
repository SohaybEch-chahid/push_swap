/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 15:45:51 by sech-cha          #+#    #+#             */
/*   Updated: 2026/10/27 10:20:05 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		len;
	int		i;
	int		j;

	if (!set || !s1)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j >= 0 && ft_strchr(set, s1[j]))
		j--;
	if (i > j)
		len = 0;
	else
		len = j - i + 1;
	trim = malloc(len + 1);
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, s1 + i, len + 1);
	return (trim);
}
