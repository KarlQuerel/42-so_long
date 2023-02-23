/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:10:19 by kquerel           #+#    #+#             */
/*   Updated: 2022/11/18 19:48:43 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c < 0 || c > 127)
		return (0);
	else
		return (1);
}

/*
int	main(void)
{
	int	c;

	c = 185;
	printf("\nRegular Function::::%i::::\n", isascii(c));
	printf("Amazing Function::::%i::::\n\n", ft_isascii(c));
	return (0);
}
*/
