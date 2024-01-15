/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:54:36 by suminkwon         #+#    #+#             */
/*   Updated: 2024/01/15 17:14:14 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier(t_print *print, char format)
{
	if (format == 'c')
		return (put_char(print, va_arg((print)->ap, int)));
	else if (format == 's')
		return (put_str(print, va_arg((print)->ap, char *)));
	else if (format == 'p')
		return (put_ptr(print, va_arg((print)->ap, void *)));
	else if (format == 'd' || format == 'i')
		return (put_num(print, va_arg((print)->ap, int)));
	else if (format == 'u')
		return (put_num_unsigned(print, va_arg((print)->ap, unsigned int)));
	else if (format == 'x')
		return (put_hex(print, va_arg((print)->ap, unsigned int), 'a'));
	else if (format == 'X')
		return (put_hex_cap(print, va_arg((print)->ap, unsigned int), 'A'));
	else if (format == '%')
	{
		if (put_char(print, '%') == -1)
			return (-1);
	}	
	return ((print)->len);
}

// int	errcheck(t_print **print, int (*f)(t_print **print, char fm), char fm)
int	errcheck(t_print *print, int n)
{
	if (n == -1)
	{
		va_end((print)->ap);
		return (-1);
	}
	return ((print)->len);
}
// void initialize_print(t_print *print)
// {
// 	print->len = 0;
// }
int	ft_printf(const char *fm, ...)
{
	t_print	print;

	print.len = 0;
	// initialize_print(&print);
	// va_start(print->ap, fm); //이걸로하면 포인터로 할당되야 가능 그래서 -> 대신 .을 씀
	// 구조체 자체에 대한 가변 인자 목록 초기화:
	// va_start(print.ap, fm);
	// 포인터를 통한 가변 인자 목록 초기화:
	// va_start(print->ap, fm);
	va_start(print.ap, fm);
	while (*fm)
	{
		if (*fm == '%')
		{
			//  함수 호출의 문맥에서는 이미 함수의 주소가 자동으로 전달되므로 추가적으로 & 연산자를 사용할 필요가 없습니다.
			if (errcheck(&print, specifier(&print, *(++fm)))== -1)
				return (-1);
		}
		else if (*fm)
		{
			if (errcheck(&print, put_char(&print, *fm)) == -1)
				return (-1);
		}
		fm++;
	}
	// va_end(print->ap);
	va_end(print.ap);
	// return (print->len);
	return (print.len);
}

// However, these are different when used as input specifier e.g. with scanf, where %d scans an integer as a signed decimal number,
// but %i defaults to decimal but also allows hexadecimal (if preceded by 0x) and octal if preceded by 0
// but with d also work with 0x in front : like same as i
// but it only prints int number without 0x anyway, so don't need to consider that 0x prefix part