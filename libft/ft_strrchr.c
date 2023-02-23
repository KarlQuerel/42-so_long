/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:22:34 by kquerel           #+#    #+#             */
/*   Updated: 2022/11/30 20:28:16 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i--;
	}
	return (NULL);
}

/*
int	main(void)
{
	char *s = "Aslknfksd,feeekekjekkjejbke";
	int	c;

	c = 'e';
	printf("\nRegular Function::::%p::::\n", strrchr(s, c));
	printf("Amazing Function::::%p::::\n\n", ft_strrchr(s, c));
	return (0);
}
*/
