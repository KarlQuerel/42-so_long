/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:09:21 by kquerel           #+#    #+#             */
/*   Updated: 2023/02/09 18:22:21 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(long int n, int base_len)
{
	int	nbr_len;

	nbr_len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		nbr_len++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / base_len;
		nbr_len++;
	}
	return (nbr_len);
}

int	ft_putnbr(long long n, char *base)
{
	unsigned long long	nbr;
	size_t				base_len;

	base_len = ft_strlen_printf(base);
	nbr = n;
	if (n < 0)
	{
		nbr = n * -1;
		ft_putchar('-');
	}
	if (nbr > base_len - 1)
		ft_putnbr(nbr / base_len, base);
	ft_putchar(base[nbr % base_len]);
	return (ft_nbrlen(n, base_len));
}

int	ft_puns(unsigned long long n, char *base)
{
	unsigned long long	nbr;
	size_t				base_len;

	base_len = ft_strlen_printf(base);
	nbr = n;
	if (nbr > base_len - 1)
		ft_putnbr(nbr / base_len, base);
	ft_putchar(base[nbr % base_len]);
	return (ft_nbrlen(n, base_len));
}

int	ft_percent(va_list ap, const char *format)
{
	char	*base;
	char	*low_b;
	char	*upp_b;

	base = "0123456789";
	low_b = "0123456789abcdef";
	upp_b = "0123456789ABCDEF";
	if (*format == 'd' || *format == 'i')
		return (ft_putnbr((long long)va_arg(ap, int), base));
	if (*format == 'x')
		return (ft_puns((unsigned long)va_arg(ap, unsigned int), low_b));
	if (*format == 'X')
		return (ft_puns((unsigned long)va_arg(ap, unsigned int), upp_b));
	if (*format == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (*format == 's')
		return (ft_putstring(va_arg(ap, char *)));
	if (*format == '%')
		return (ft_putchar('%'));
	if (*format == 'u')
		return (ft_puns((unsigned long)va_arg(ap, unsigned int), base));
	if (*format == 'p')
		return (ft_pointer(va_arg(ap, unsigned long long), low_b, 0));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		len;

	va_start (ap, format);
	if (format == NULL)
		len = ft_putstring("(null)");
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_percent(ap, &format[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end (ap);
	return (len);
}
