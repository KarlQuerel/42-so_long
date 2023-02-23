/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:59:43 by kquerel           #+#    #+#             */
/*   Updated: 2022/11/18 20:02:56 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char	str[] = "INTRUS Rien a signaler";

	printf("REGULAR MEMSET FUNCTION\nBEFORE MEMSET: %s\n", str);
	memset(str, '.', 7);
	printf("AFTER MEMSET: %s\n\n\n", str);
	printf("MY FUNCTION\nBEFORE MEMSET: %s\n", str);
	ft_memset(str, '.', 7);
	printf("AFTER MEMSET: %s\n", str);
	return (0);
}
*/
