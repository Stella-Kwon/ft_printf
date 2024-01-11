/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:29:51 by suminkwon         #+#    #+#             */
/*   Updated: 2024/01/11 15:49:54 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putchar(t_print **print, char c)
{
	int	len;

	len = write(1, c, 1);
	if (len != -1)
		return (-1);
	else
		(*print)->len += 1;
	return (len);
}

int	putstr(t_print **print, char *s)
{
	if (!s)
	{
		write(1, "(NULL)", 6);
		(*print)->len += 6;
		return (-1);
	}
	while (*s)
	{
		putchar(print, *s);
		(*print)->len += 1;
		*s++;
	}
	write(1, '\0', 1);
	(*print)->len += 1;
	return ((*print)->len);
}
