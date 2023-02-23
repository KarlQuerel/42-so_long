/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:08:58 by kquerel           #+#    #+#             */
/*   Updated: 2023/02/23 21:58:40 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen_lib(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	if (len == 0)
		return (1);
	return (len);
}

char	*ft_itoa(int n)
{
	char			*nbr;
	unsigned int	nb;
	int				i;

	i = ft_nbrlen_lib(n);
	nbr = (char *)malloc(sizeof(char) * (i + 1));
	if (nbr == NULL)
		return (NULL);
	nbr[i--] = '\0';
	if (n == 0)
		nbr[0] = '0';
	if (n < 0)
	{
		nbr[0] = '-';
		nb = n * -1;
	}
	else
		nb = n;
	while (nb > 0)
	{
		nbr[i--] = (nb % 10) + 48;
		nb /= 10;
	}
	return (nbr);
}
