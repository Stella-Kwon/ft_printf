NAME = libft.a

SRCS = ft_toupper.c\
		ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_split.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strmapi.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_tolower.c\
		./get_next_line/get_next_line.c\
		./get_next_line/get_next_line_utils.c

SRCS_BONUS = ft_lstiter_bonus.c\
			ft_lstlast_bonus.c\
			ft_lstdelone_bonus.c\
			ft_lstadd_front_bonus.c\
			ft_lstsize_bonus.c\
			ft_lstclear_bonus.c\
			ft_lstadd_back_bonus.c\
			ft_lstnew_bonus.c\
			ft_lstmap_bonus.c\
			get_next_line/get_next_line_bonus.c\
			get_next_line/get_next_line_utils_bonus.c

INCLUDES = -I ./libft.h -I ./get_next_line/get_next_line.h

INCLUDES_BONUS = -I ./libft.h -I ./get_next_line/get_next_line_bonus.h

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all_bonus : all bonus

all: $(NAME)

$(NAME): $(OBJS)
#		gcc $(FLAGS) $(INCLUDES) $(SRCS) 이렇게 하면 ./get_next_line에 안들어가져서 따로 빼주기 -o 만드는파일
		ar rcs $(NAME) $(OBJS)

$(OBJS): %.o: %.c 
		gcc $(FLAGS) $(INCLUDES) -o $@ -c $<

#-c main.c: 소스 코드를 컴파일하되 링크는 하지 말아라.
#-o main.o: 출력 파일의 이름을 main.o로 지정하라.
#$(OBJS): %.o: %.c 룰은 Makefile에서 빌드 규칙을 정의하는 부분입니다. 
#이 규칙은 .c 확장자를 가진 소스 파일을 .o 확장자를 가진 오브젝트 파일로 컴파일하는 데 사용됩니다.
#$@는 현재 목표(오브젝트 파일)를 나타냅니다. => : %.o
#$<는 현재 목표에 필요한 종속 항목(소스 파일) 중 첫 번째 항목을 나타냅니다. => : %.c


bonus: $(OBJS_BONUS)
		ar rcs $(NAME) $(OBJS_BONUS)

$(OBJS_BONUS): %.o: %.c
		gcc $(FLAGS) $(INCLUDES_BONUS) -o $@ -c $<
		
clean:
		rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
		rm -rf $(NAME)

re: fclean all bonus

.PHONY: all bonus fclean clean re