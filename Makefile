NAME = libftprintf.a

SRCS = ft_printf.c\
		ft_num.c\
		ft_char.c\
		ft_hexa.c

INCLUDE = -I./ -I./libft
# -I.: This includes the current directory (root directory) in the search path.
# -I./subdir: This includes the subdir directory in the search path.
# -I./부분은 굳이 필요 없는것이.. 같은 폴더내에서 이미 h파일이 있고 소스파일에 include로 printf.h를 했기 때문에

LIBFT_DIR := ./libft

LIBFT = $(LIBFT_DIR)/libft.a

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)	
	ar -rcs $(NAME) $(OBJS) 
# ar -rcs $(NAME) $(OBJS) ./libft/*.o로 하니까 ./get_next_line/으로 들어가는 폴더 패스가 인식이안되서 cp로 바꿈
# ar -t libftprintf.a    => .a 파일 안에 잘 .o파일있나 확인하는법 

$(LIBFT):
	$(MAKE) -C libft
	
%.o : %.c
	gcc $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
		make -C libft/ clean
		rm -rf $(OBJS)

fclean: clean
		make -C libft/ fclean
		rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
