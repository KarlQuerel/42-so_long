/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:13:26 by kquerel           #+#    #+#             */
/*   Updated: 2023/02/09 18:22:06 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>

size_t	ft_strlen_printf(char *str);
int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstring(char *str);
int		ft_pointer(unsigned long long ptr, char *base, int trigger);
int		ft_putnbr(long long n, char *base);
int		ft_puns(unsigned long long n, char *base);
int		ft_percent(va_list ap, const char *format);
int		ft_nbrlen(long int n, int base_len);
int		ft_ptrlen(unsigned long long n, int base_len);

#endif
