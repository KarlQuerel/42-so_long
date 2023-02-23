/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:04:14 by kquerel           #+#    #+#             */
/*   Updated: 2023/02/09 18:30:50 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	size_ret;

	if (dst == NULL)
		i = 0;
	else
		i = ft_strlen_lib(dst);
	j = ft_strlen_lib(src);
	size_ret = i + j;
	if (size == 0 || i > size)
		return (size + j);
	j = 0;
	while (src[j] && (i + j) < size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (size_ret);
}

/*
int	main(void)
{
	char str1[] = "gkjgjh";
	char str2[] = " tre faim et a resolu mon code";
	size_t	n;

	n = 10;
	printf("\n----Before----\ndest = %s\nsrc = %s\n", str1, str2);
	//printf("size: %li\n", strlcat(str1, str2, n));
	//strlcat(str1, str2, n);
	ft_strlcat(str1, str2, n);
	printf("size: %li\n", ft_strlcat(str1, str2, n));
	printf("----After----\ndest = %s\nsrc = %s\n\n", str1, str2);
	return (0);
}
*/
