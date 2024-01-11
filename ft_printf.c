/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:54:36 by suminkwon         #+#    #+#             */
/*   Updated: 2024/01/11 17:49:15 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	error_check(t_print **print, int (*f)(t_print **print, char format))
{
	if (f == -1)
	{
		va_end((*print)->ap);
		return (-1);
	}
	return ((*print)->len);
}

int	ft_printf(const char *format, ...)
{
	t_print	*print;

	print->len = 0;
	va_start(print->ap, format);
	while (*format)
	{
		if (*format == '%' && *(++format))
		{
			if (error_check(&print, check_specifier(&print, *(++format)))== -1)
				return (-1);
		}
		else if (*format)
		{
			if (error_check(&print, putchar(&print, *format)) == -1)
				return (-1);
			// else
			// 	print->len += 1;
		}
	}
	va_end(print->ap);
	return (print->len);
}

int	check_specifier(t_print **print, char format)
{
	if (format == 'c')
		return (putchar(print, va_arg((*print)->ap, char)));
	else if (format == 's')
		return (putstr(print, va_arg((*print)->ap, char *)));
	else if (format == 'p')
		return (putptr(print, va_arg((*print)->ap, unsigned long)));
	else if (format == 'd' || format == 'i')
		return (putnum(print, va_arg((*print)->ap, int)));
	else if (format == 'u')
		return(putnum_unsigned(print, va_arg((*print)->ap, unsigned int)));
	else if (format == 'x')
		return(puthex(print, va_arg((*print)->ap, unsigned long)));
	else if (format == 'X')
		return(puthex_cap(print, va_arg((*print)->ap, unsigned long)));
	else if (format == '%')
		
	return ((*print)->len);
}

// However, these are different when used as input specifier e.g. with scanf, where %d scans an integer as a signed decimal number,
// but %i defaults to decimal but also allows hexadecimal (if preceded by 0x) and octal if preceded by 0
// but with d also work with 0x in front : like same as i