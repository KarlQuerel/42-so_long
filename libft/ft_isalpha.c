/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:38:30 by kquerel           #+#    #+#             */
/*   Updated: 2022/11/18 18:32:54 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1024);
	else
		return (0);
}

/*
int	main(void)
{
	int	c;

	c = 'l';
	printf("\nRegular Function::::%i::::\n", isalpha(c));
	printf("Amazing Function::::%i::::\n\n", ft_isalpha(c));
	return (0);
}
*/
