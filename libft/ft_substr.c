/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:36:50 by kquerel           #+#    #+#             */
/*   Updated: 2023/02/09 18:29:10 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_lib(char const *s, unsigned int start, size_t len)
{
	char			*new_str;
	unsigned int	j;
	size_t			i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen_lib(s) - 1)
		len = 0;
	if (len > ft_strlen_lib(s) - start - 1)
		len = ft_strlen_lib(s) - start;
	new_str = malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[j])
	{
		if (j >= start && i < len)
			new_str[i++] = s[j];
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}
