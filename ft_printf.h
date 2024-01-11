/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:54:49 by suminkwon         #+#    #+#             */
/*   Updated: 2024/01/11 17:53:20 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//# include <stdlib.h> //libft에 있고
//# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

/// @brief linked list for the printing line and lenth of it
typedef struct s_print
{
	va_list	ap;
	int		len;
}	t_print;

int	ft_printf(const char	*format, ...);
// int	putchar(t_print **print, char c);
// int	putstr(t_print **print, char *s);

#endif