NAME = libftprintf.a

SRCS = ft_printf.c\
		ft_num.c\
		ft_char.c\
		ft_hexa.c

INCLUDE = -I./ -I./libft

LIBFT_DIR := ./libft

LIBFT = $(LIBFT_DIR)/libft.a

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)	
	ar -rcs $(NAME) $(OBJS) 

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