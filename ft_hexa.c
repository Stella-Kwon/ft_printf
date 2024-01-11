/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:29:59 by suminkwon         #+#    #+#             */
/*   Updated: 2024/01/11 17:44:35 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int putptr(t_print **print, void *n)
{
	put_char('0');
	put_char('x');
	return ((*print)->len);
}

int puthex(t_print **print, unsigned long n)
{
	return ((*print)->len);
}

int puthex_cap(t_print **print, unsigned long n)
{
	return ((*print)->len);
}