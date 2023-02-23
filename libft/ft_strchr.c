/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:42:45 by kquerel           #+#    #+#             */
/*   Updated: 2023/02/09 18:25:58 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_lib(const char *s, int c)
{
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

/*
int	main(void)
{
	const char *s = "INTRUSeHeliabonsoir";
	int	c;

	c = 'e';
	printf("\nRegular Function::::%s::::\n", strchr(s, c));
	printf("Amazing Function::::%s::::\n\n", ft_strchr(s, c));
	return (0);
}
*/
