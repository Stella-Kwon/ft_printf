/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:29:36 by suminkwon         #+#    #+#             */
/*   Updated: 2024/01/15 16:52:43 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_num(t_print *print, int n)
{
	int	num;

	num = n;
	if (num == -2147483648)
	{
		if (put_char(print, '-') == -1)
			return (-1);
		if (put_char(print, '2') == -1)
			return (-1);
		num = 147483648;
	}
	if (num < 0)
	{
		if (put_char(print, '-') == -1)
			return (-1);
		num *= -1;
	}
	if (put_num_unsigned(print, num) == -1)
		return (-1);
	return ((print)->len);
}

int	put_num_unsigned(t_print *print, unsigned int n)
{
	if (n >= 0 && n < 10)
	{
		if (put_char(print, '0' + n) == -1)
			return (-1);
	}
	else if (n >= 10)
	{
		// printf("몫 계산 전 n: %u\n", n);
		if (put_num_unsigned(print, n / 10) == -1)
		{
			// printf("몫");
			return (-1);
		}
		// printf("나머지 계산 전 n: %u\n", n);
		// if (put_char(print, '0' + (n % 10)) == -1) // 아무래도 10진수라 
		if (put_num_unsigned(print, n % 10) == -1)
		{
			// printf("나머지");
			return (-1); 
		}

	}
	return ((print)->len);
}
//10진수 16진수 다같이 쓰느느 함수를 만들려하면
//macro 문자열로 만들어서 그걸 base로 두고
//base_len 을 각각 strlen()으로 구해
// write(1, (base + nbr), 1) 로 프린트 해주면 
//base주소의 위치에서 nbr만큼가서 그 부분을 프린트 해준다.

// #include <unistd.h>
// int print_from_base(char *base, int nbr) {
//     unsigned long base_len = ft_strlen(base);

//     if (nbr >= base_len) {
//         if (ft_putnbr_base_ul(nbr / base_len, base) != 0)
//             return (-1);
//         if (ft_putnbr_base_ul(nbr % base_len, base) != 0)
//             return (-1);
//     } else {
//         if (write(1, base + nbr, 1) != 1)
//             return (-1);
//     }

//     return 0;
// }

// int main() {
//     char base[] = "0123456789abcdef";
//     int nbr = 12;
//     if (print_char_from_base(base, nbr) == -1)
//         return 1;  // 에러 처리

//     return 0;
// }

// 이렇게 출력된다...