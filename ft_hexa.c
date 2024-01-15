/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:29:59 by suminkwon         #+#    #+#             */
/*   Updated: 2024/01/15 17:23:46 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_ptr(t_print *print, void *n)
{
	unsigned long	num;

	num = (unsigned long)n;
	// if (!n)
	// 	return ((print)->len); //다음에 붙여 나올 문자열을 생각해서 return -1해선 안됌
	if (put_str(print, "0x") == -1)
		return (-1);
	if (put_hex(print, num, 'a') == -1)
		return (-1);
	return ((print)->len);
}

int put_hex(t_print *print, unsigned long n, char c)
{
	if (n >= 0 && n < 10) // 0-9
	{
		if (put_char(print, '0' + n) == -1)
			return (-1);
	}
	if (10 <= n && n < 16) // A-F or a-f
	{
		// char digit = 'a' + (n - 10);
    	// printf("\nn: %lu, char: %c (ASCII: %d)\n", n, digit, digit);
		if (put_char(print, c + (n - 10)) == -1)
			return (-1);
	}
	if (n >= 16)
	{
		if (put_hex(print, n / 16, c) == -1)
			return (-1);
		if (put_hex(print, n % 16, c) == -1)
			return (-1);
	}
	return ((print)->len);
}


int	put_hex_cap(t_print *print, unsigned int n, char c)
{
	return (put_hex(print, n, c));
}