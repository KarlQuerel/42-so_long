/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:44:05 by kquerel           #+#    #+#             */
/*   Updated: 2022/11/18 19:43:18 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (8);
	else
		return (0);
}

/*
int	main(void)
{
	int	c;

	c = 'j';
	printf("\nRegular Function::::%i::::\n", isalnum(c));
	printf("Amazing Function::::%i::::\n\n", ft_isalnum(c));
}
*/
