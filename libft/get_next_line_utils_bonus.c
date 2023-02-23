/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:15:29 by kquerel           #+#    #+#             */
/*   Updated: 2023/02/14 14:38:20 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, int c)
{
	if (s == NULL)
		return (NULL);
	if (c == 0)
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	size_t	size;
	char	*new_str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1;
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

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	char			*new_str;
	unsigned int	j;
	size_t			i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen_gnl(s) - 1)
		len = 0;
	if (len > ft_strlen_gnl(s) - start - 1)
		len = ft_strlen_gnl(s) - start;
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
