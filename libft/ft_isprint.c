/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:33:09 by kquerel           #+#    #+#             */
/*   Updated: 2022/11/21 20:52:27 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	else
		return (0);
}

/*
int	main(void)
{
	int	c;

	c = 9999;
	printf("\nRegular Function::::%i::::\n", isprint(c));
	printf("Amazing Function::::%i::::\n\n", ft_isprint(c));
	return (0);
}
*/
