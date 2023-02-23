/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:51:14 by kquerel           #+#    #+#             */
/*   Updated: 2022/11/28 15:48:29 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	char	*s1 = "abcdef";
	char	*s2 = "abcdwx";
	size_t	n;

	n = 4;
	printf("\nRegular function::::%i::::\n", strncmp(s1, s2, n));
	printf("Amazing function::::%i::::\n\n", ft_strncmp(s1, s2, n));
	return (0);
}
*/
