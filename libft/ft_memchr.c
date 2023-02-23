/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:01:29 by kquerel           #+#    #+#             */
/*   Updated: 2022/12/02 16:30:24 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long int	i;

	i = 0;
	while (i < n)
	{
		if (((char *)s)[i] == (char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char *s = "Karl a faim";
	int	c;
	size_t	n;

	c = 'a';
	n = 50;
	printf("\nRegular Function::::%p::::\n", memchr(s, c, n));
	printf("Amazing Function::::%p::::\n\n", ft_memchr(s, c, n));
	return (0);
}
*/
