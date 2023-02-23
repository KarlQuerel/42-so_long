/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:16:15 by kquerel           #+#    #+#             */
/*   Updated: 2022/11/21 20:41:09 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

/*
int	main(void)
{
	char s1[] = "AAaaaAAaaZzzZZzzzKaRl ET yako oNt Faim!!??:";
	int	i;
	
	i = 0;
	while (s1[i])
	{
		//printf("%c", (toupper(s1[i])));
		printf("%c", (ft_toupper(s1[i])));
		i++;
	}
	return (0);
}
*/
