/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:48:03 by kquerel           #+#    #+#             */
/*   Updated: 2023/02/09 18:22:40 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_printf(char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0' && str)
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstring(char *str)
{
	int	i;

	if (str == NULL)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_ptrlen(unsigned long long n, int base_len)
{
	size_t	nbr_len;

	nbr_len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / base_len;
		nbr_len++;
	}
	return (nbr_len);
}

int	ft_pointer(unsigned long long ptr, char *base, int trigger)
{
	unsigned long long	nbr;

	nbr = ptr;
	if (nbr == 0)
		return (write(1, "(nil)", 5));
	if (trigger == 0)
		write(1, "0x", 2);
	if (nbr > 15)
		ft_pointer(nbr / 16, base, 1);
	ft_putchar(base[nbr % 16]);
	return (ft_ptrlen(nbr, ft_strlen_printf(base)) + 2);
}
