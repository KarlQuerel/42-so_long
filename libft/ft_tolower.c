/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:37:32 by kquerel           #+#    #+#             */
/*   Updated: 2022/11/18 20:19:25 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

/*
int	main(void)
{
	char	s1[] = "KaRl Et YaKO ONt FaiM!!?";
	int	i;

	i = 0;	
	while (s1[i])
	{
		printf("%c", (tolower(s1[i])));
		//printf("%c", (ft_tolower(s1[i])));
		i++;
	}
}
*/
