/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:54:49 by suminkwon         #+#    #+#             */
/*   Updated: 2024/01/15 17:20:10 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//# include <stdlib.h> //libft에 있어서 그냥 libft.h로 추가
//# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_print
{
	va_list	ap;
	int		len;
}	t_print;

int	ft_printf(const char	*format, ...);
int	put_char(t_print *print, char c);
int	put_str(t_print *print, char *s);
int	put_hex_cap(t_print *print, unsigned int n, char c);
int	put_hex(t_print *print, unsigned long n, char c);
int	put_ptr(t_print *print, void *n);
int	put_num_unsigned(t_print *print, unsigned int n);
int	put_num(t_print *print, int n);

#endif