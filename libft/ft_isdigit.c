/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:37:23 by kquerel           #+#    #+#             */
/*   Updated: 2022/11/18 19:13:30 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	else
		return (0);
}

/*
int	main(void)
{
	int	c;

	c = '5';
	printf("\nRegular Function::::%i::::\n", isdigit(c));
	printf("Amazing Function::::%i::::\n\n", ft_isdigit(c));
	return (0);
}
*/
