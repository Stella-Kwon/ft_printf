/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:54:26 by suminkwon         #+#    #+#             */
/*   Updated: 2024/01/15 17:24:07 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

void test_char(char* format, char arg)
{
	int mine;
	int origin;

	mine = ft_printf(format, arg);
	printf("\n");
	origin = printf(format, arg); 
	//char *format = "" 해서 printf(format); 할땐 error가 난다.
	//밑에와 같은 형식으론 가능하다.
	//	char *format = "%c";
	//	char arg = 'A';
	//	printf(format, arg);

	printf("<return value>\nmine : %d\norigin : %d\n", mine, origin);
	printf("\n");
}

void test_two_str(char* format, char *arg, char *arg2)
{
	int mine;
	int origin;

	mine = ft_printf(format, arg);
	printf("\n");
	origin = printf(format, arg);
	printf("\n");
	printf("<return value>\nmine : %d\norigin : %d\n", mine, origin);

	printf("2nd\n");
	mine = ft_printf(format, arg2);
	printf("\n");
	origin = printf(format, arg2);

	printf("<return value>\nmine : %d\norigin : %d\n", mine, origin);
	printf("\n");
}

void test_num(char* format, int arg, int arg2)
{
	int mine;
	int origin;

	mine = ft_printf(format, arg);
	printf("\n");
	origin = printf(format, arg);
	printf("\n");
	printf("<return value>\nmine : %d\norigin : %d\n", mine, origin);

	printf("2nd\n");
	mine = ft_printf(format, arg2);
	printf("\n");
	origin = printf(format, arg2);

	printf("<return value>\nmine : %d\norigin : %d\n", mine, origin);
	printf("\n");
}

void test_num_unsigned(char* format, unsigned int arg, unsigned int arg2)
{
	int mine;
	int origin;

	mine = ft_printf(format, arg);
	printf("\n");
	origin = printf(format, arg);
	printf("\n");
	printf("<return value>\nmine : %d\norigin : %d\n", mine, origin);

	printf("2nd\n");
	mine = ft_printf(format, arg2);
	printf("\n");
	origin = printf(format, arg2);

	printf("<return value>\nmine : %d\norigin : %d\n", mine, origin);
	printf("\n");
}

void triple_test_ptr(char* format, unsigned long arg, unsigned long arg2, unsigned long arg3)
{
	int mine;
	int origin;

	mine = ft_printf(format, arg);
	printf("\n");
	origin = printf(format, arg);
	printf("\n");
	printf("<return value>\nmine : %d\norigin : %d\n", mine, origin);

	printf("2nd\n");
	mine = ft_printf(format, arg2);
	printf("\n");
	origin = printf(format, arg2);

	printf("<return value>\nmine : %d\norigin : %d\n", mine, origin);
	printf("\n");

	printf("3nd\n");
	mine = ft_printf(format, arg3);
	printf("\n");
	origin = printf(format, arg3);

	printf("<return value>\nmine : %d\norigin : %d\n", mine, origin);
	printf("\n");
}

void test_hex(char* format, unsigned long arg, unsigned long arg2, unsigned long arg3)
{
	int mine;
	int origin;

	mine = ft_printf(format, arg);
	printf("\n");
	origin = printf(format, arg);
	printf("\n");
	printf("<return value>\nmine : %d\norigin : %d\n", mine, origin);

	printf("2nd\n");
	mine = ft_printf(format, arg2);
	printf("\n");
	origin = printf(format, arg2);

	printf("<return value>\nmine : %d\norigin : %d\n", mine, origin);
	printf("\n");

	printf("3nd\n");
	mine = ft_printf(format, arg3);
	printf("\n");
	origin = printf(format, arg3);

	printf("<return value>\nmine : %d\norigin : %d\n", mine, origin);
	printf("\n");
}

void test_hex_cap(char* format, unsigned long arg, unsigned long arg2, unsigned long arg3)
{
	int mine;
	int origin;

	mine = ft_printf(format, arg);
	printf("\n");
	origin = printf(format, arg);
	printf("\n");
	printf("<return value>\nmine : %d\norigin : %d\n", mine, origin);

	printf("2nd\n");
	mine = ft_printf(format, arg2);
	printf("\n");
	origin = printf(format, arg2);

	printf("<return value>\nmine : %d\norigin : %d\n", mine, origin);
	printf("\n");

	printf("3nd\n");
	mine = ft_printf(format, arg3);
	printf("\n");
	origin = printf(format, arg3);

	printf("<return value>\nmine : %d\norigin : %d\n", mine, origin);
	printf("\n");
}

void test_noarg(char *str)
{
	int mine;
	int origin;

	origin = printf("%s\n",str);
	printf("\n");
	mine = ft_printf("%s\n",str);
	printf("\n");
	printf("<return value>\nmine : %d\norigin : %d\n",  mine, origin);
	printf("\n");
}

int	main(void)
{

	printf("---------PUTCHAR-----------\n");
	test_char("%c\n",'c');
	test_char("%cc\n",'X');
	test_char("%c\n", '\0');

	printf("---------PUTSTR-----------\n");
	test_two_str("%s\n","hello", "HELLO");
	test_two_str("%s\n","NiCe\t!!!!", "\n\n");
	test_two_str("with ss : %ss\n","NULL", NULL);

	printf("---------PUTNUM-----------\n");
	test_num(" with 'd' : %d\n",2147483647, -2147483648);
	// test_num(" with 'i' : %i\n",2147483648, -2147483649);
	test_num(" with 'dd' : %dd\n",2147483647, -2147483648);
	test_num(" with 'ii' : %ii\n",-2147483648, 2147483647);
	// test_num("%d\n2 : %i\n",NULL, NULL);

	printf("---------PUTNUM_UNSIGNED-----------\n");
	test_num_unsigned("%u\n", -2147483648, 2147483647);
	test_num_unsigned("with uu : %uu\n" ,123456, 2147483648);

	printf("---------PUTPTR-----------\n");
	triple_test_ptr("%p\n", 0, 15, -14523);
	triple_test_ptr("with pp : %pp\n", ULONG_MAX, LONG_MAX , INT_MAX);
	triple_test_ptr("with pp : %pp\n", -1, -789, 15);


	printf("---------PUTHEX-----------\n");
	test_hex("%x\n", INT_MAX, 0, INT_MIN);
	test_hex("with xx :%xx\n", 100230, 1085, -2651000);

	printf("---------PUTHEX_CAP-----------\n");
	test_hex_cap("%X\n", INT_MAX, 0, INT_MIN);
	test_hex_cap("with Xx: %XX\n", 100230, 1085, -2651000);


	printf("---------NO_ARGUMENTS-----------\n");
	test_noarg("");
	test_noarg("\x01\a\v\b\f\r\n\tbd");


// \x01: ASCII 코드 1에 해당하는 문자.
// 	\x 뒤에 오는 두 자리 16진수는 해당 ASCII 문자의 코드 값을 나타냅니다.
// \a: 소리 알림 또는 벨 소리를 생성합니다.
// \v: 수직 탭 문자를 나타냅니다.
// \b: 백스페이스 문자를 나타냅니다.
// \f: 폼 피드 문자를 나타냅니다.
// \r: 캐리지 리턴 문자를 나타냅니다.
// \n: 새 줄 문자를 나타냅니다.
// \t: 탭 문자를 나타냅니다.

	printf("---------%%-----------\n");
	test_noarg("%%gd%c");
	test_noarg("");

	return 0;
}
