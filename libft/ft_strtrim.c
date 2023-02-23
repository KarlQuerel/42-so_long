/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:20:47 by kquerel           #+#    #+#             */
/*   Updated: 2023/02/09 18:31:30 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_char_is_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static	size_t	ft_get_size(char const *s1, char const *set)
{
	int		i;
	size_t	size;

	i = 0;
	size = ft_strlen_lib(s1);
	while (ft_char_is_set(s1[i], set) == 1)
	{
		i++;
		size--;
	}
	i = ft_strlen_lib(s1) - 1;
	if (size == 0)
		return (0);
	while (ft_char_is_set(s1[i], set) == 1)
	{
		size--;
		i--;
	}
	return (size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*new_str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = ft_get_size(s1, set);
	new_str = (char *)malloc(sizeof(char) * i + 1);
	if (new_str == NULL)
		return (NULL);
	end = ft_strlen_lib(s1) - 1;
	start = 0;
	while (ft_char_is_set(s1[start], set) == 1)
		start++;
	while (ft_char_is_set(s1[end], set) == 1)
		end--;
	i = 0;
	while (start <= end)
		new_str[i++] = s1[start++];
	new_str[i] = '\0';
	return (new_str);
}
