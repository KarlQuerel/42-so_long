/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:03:04 by kquerel           #+#    #+#             */
/*   Updated: 2023/02/09 18:30:57 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size <= 0)
	{
		while (src[i] != '\0')
			i++;
		return (i);
	}
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	i = ft_strlen_lib(src);
	return (i);
}

/*
int	main(void)
{
	char src[] = "Helia et Karl";
	char *dst = src + 2;
	char	src2[] = "Helia et Karl";
	char	*dst2 = src2 + 2;
	size_t	n;

	n = 99;
	printf("\nNORMAL FUNCTION\n----Before----\ndest = %s\nsrc = %s\n", dst, src);
	strlcpy(dst, src, n);
	printf("----After----\ndest = %s\nsrc = %s\n", dst, src);
	printf("----Return = %li\n", strlcpy(dst, src, n));
	printf("\nMy FUNCTION\n----Before----\ndest = %s\nsrc = %s\n", dst2, src2);
	ft_strlcpy(dst2, src2, n);
	printf("----After----\ndest = %s\nsrc = %s\n", dst2, src2);
	printf("----Return = %li\n", ft_strlcpy(dst2, src2, n));
	return (0);

}
*/
