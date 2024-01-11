NAME = libftprintf.a

SRCS = ft_printf.c\
		ft_num.c\
		ft_char.c\
		ft_hexa.c

INCLUDE = -I ./ft_printf.h -I ./libft.h
#이 헤더가 쓰일때만 추가해주면된다.-I ./libft.h -I./libft/get_next_line/get_next_line.h -I./libft/get_next_line/get_next_line_bonus.h
#libft.h는 사용하니까 넣어주고 ft_printf.h에도 추가해줘야하는거 잊지마.
LIB = -L ./libft -lft

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) COPY_LIB
	ar -rcs $(NAME) $(OBJS)

$(OBJS) : %.o : %.c
	gcc $(FLAGS) $(INCLUDE) $(LIB) -c $< -o $@

COPY_LIB : libft.a
	cp libft/libft.a libftprintf.a

libft.a :
#make -C libft/ bonus 명령어는 
#libft/ 디렉터리에서 Makefile을 찾아 all_bonus 규칙을 실행
	make -C libft/ all_bonus

#@$(MAKE)OBJS="$(OBJS) $(OBJSBONUS)" --no-print-directory : make bonus and madatory objects file at the same time.