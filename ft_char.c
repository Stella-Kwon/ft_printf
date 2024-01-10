/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:29:51 by suminkwon         #+#    #+#             */
/*   Updated: 2024/01/09 16:49:54 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putchar(t_print **print, char format)
{
	int	len;

	len = write(1, &format, 1);
	if (len != -1)
		return (-1);
	else
		(*print)->len += 1;
	return (len);
}

int ft_putstr(t_print **print, char *s)
{
	if (!s)
	{
		write(1, "(NULL)", 6);
		(*print)->len += 6;
		return (-1);
	}
	
	return ()
}