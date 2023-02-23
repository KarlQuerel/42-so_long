/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:31:24 by kquerel           #+#    #+#             */
/*   Updated: 2023/02/09 18:28:52 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_lib(char const *s1, char const *s2)
{
	int		i;
	int		j;
	size_t	size;
	char	*new_str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen_lib(s1) + ft_strlen_lib(s2) + 1;
	new_str = (char *)malloc(sizeof(char) * (size));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	return (new_str);
}
