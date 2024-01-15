NAME = libftprintf.a

SRCS = ft_printf.c\
		ft_num.c\
		ft_char.c\
		ft_hexa.c

INCLUDE = -I ./ft_printf.h -I ./libft.h
#이 헤더가 쓰일때만 추가해주면된다.-I ./libft.h -I./libft/get_next_line/get_next_line.h -I./libft/get_next_line/get_next_line_bonus.h
#libft.h는 사용하니까 넣어주고 ft_printf.h에도 추가해줘야하는거 잊지마.

## 현재 libftprintf.a파일을 만들어주고 있는 것이기에 필요가 없고,
## 그렇기에 paco할때 에러남 -> 그래서 주석달기
# LIB = -L. -lftprintf
## -L.는 현재 디렉토리에서 라이브러리를 찾도록 하고, -lft는 libftprintf.a를 링크하도록 설정
## 그래서 libft.a를 현 디렉토리에 옮겨와 libftprintf.a라 합쳐줘야해서 COPY_LIB libft.a 룰을 만든것
FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : COPY_LIB $(OBJS) 
	ar -rcs $(NAME) $(OBJS)

$(OBJS) : %.o : %.c
	gcc $(FLAGS) $(INCLUDE) -c $< -o $@
# gcc $(FLAGS) $(INCLUDE) $(LIB) -c $< -o $@

COPY_LIB : libft.a
	cp libft/libft.a libftprintf.a

libft.a :
#make -C libft/ bonus 명령어는 
#libft/ 디렉터리에서 Makefile을 찾아 all_bonus 규칙을 실행
	make -C libft/ all_bonus
clean:
		make -C libft/ clean
		rm -rf $(OBJS) $(OBJS_BONUS)
		rm -rf .timestamps
fclean: clean
		make -C libft/ fclean
		rm -rf $(NAME)

re: fclean all
