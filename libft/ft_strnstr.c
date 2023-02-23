/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:11:18 by kquerel           #+#    #+#             */
/*   Updated: 2022/11/30 15:51:42 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (i < len && len > 0 && big[i] != '\0')
	{
		j = 0;
		while ((i + j) < len && big[i + j] == little[j] && little [j] != '\0')
		{
			j++;
			if (little[j] == '\0')
				return (&((char *)big)[i]);
		}
		i++;
	}
	return (NULL);
}
