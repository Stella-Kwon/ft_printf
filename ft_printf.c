/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:54:36 by suminkwon         #+#    #+#             */
/*   Updated: 2024/01/09 16:44:18 by suminkwon        ###   ########.fr       */
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
		return (put_char(print,format));
	else if (format == 's')
	{
		
	}
	else if (format == 'p')
	{
		
	}
	else if (format == 'd' || format == 'i')
	{
		
	}
	else if (format == 'u')
	{
		
	}
	else if (format == 'x')
	{
		
	} 
	else if (format == 'X')
	{
		
	} 
	else if (format == '%')
	{
		
	}
	return (print->len);
}
