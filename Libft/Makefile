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

bonus : .timestamps
.timestamps: $(OBJS_BONUS)
		touch .timestamps
		ar rcs $(NAME) $(OBJS_BONUS)

$(OBJS_BONUS): %.o: %.c
		gcc $(FLAGS) $(INCLUDES_BONUS) -o $@ -c $<
		
clean:
		rm -rf $(OBJS) $(OBJS_BONUS)
		rm -rf .timestamps
fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all bonus fclean clean re all_bonus

#-c main.c: 소스 코드를 컴파일하되 링크는 하지 말아라.
#-o main.o: 출력 파일의 이름을 main.o로 지정하라.
#$(OBJS): %.o: %.c 룰은 Makefile에서 빌드 규칙을 정의하는 부분입니다. 
#이 규칙은 .c 확장자를 가진 소스 파일을 .o 확장자를 가진 오브젝트 파일로 컴파일하는 데 사용됩니다.
#$@는 현재 목표(오브젝트 파일)를 나타냅니다. => : $(OBJS)
#$<는 현재 목표에 필요한 종속 항목(소스 파일) 중 첫 번째 항목을 나타냅니다. => : %.o : %.c

#make는 목표를 만들기 위해 필요한 다른 파일들을 빌드할때 의존성 체인을 따라가기 떄문에 올바른 의존성이 설정되어야 한다.
 # Make는 파일의 타임스탬프를 비교하여 파일이 최신인지 여부를 판단하고, 최신이 아니라면 해당 파일을 재빌드합니다
#그래서 touch .bonus넣어주어 이미 .touch파일이 존재하면 .phony에서 이미 bonus 파일이 

#그럼 왜 make all은 안됐을까?
#  Make checks the timestamps of the dependencies and the target. 
# If the dependencies have not been modified since the last build, and the target is up to date, 
# Make concludes that there is nothing to be done and prints "make: Nothing to be done for `all'."
# .PHONY는 Makefile에서 사용되는 특별한 명령어로, 특정한 타겟이 실제 파일과 관련이 없음을 Make에게 알려주는 역할을 합니다. 
# 이는 주로 해당 타겟이 다른 파일로부터 의존성을 가지고 있지 않거나 특정한 명령을 실행하기 위한 용도로 사용됩니다.

# 일반적으로 Make는 파일의 타임스탬프를 비교하여 파일이 최신인지 여부를 판단하고, 최신이 아니라면 해당 파일을 재빌드합니다. 
# 그러나 .PHONY로 선언된 타겟은 파일과 연관이 없으므로 파일의 타임스탬프를 체크하지 않고 항상 재빌드하게 됩니다.

#즉, 파일의 이름이 명령어와 같을 수 있는 상황을 방지하기 위해 사용하는 것이다. 

# all, clean, fclean 은 명령어 이기도 하지만 파일이라고 make는 인식하기 때문에
# 그래서 .phony에 넣어서 이 이름의 파일은 진짜 파일이 명령어이며 아니고 또한 오랜된파일이라고 인식하게하여(timmestance) 계속 빌드 할 수 있도록 하는것이다.

# all 이 그렇다고 계속 되나? 그건아니다 
# rebuil는 timestamps에 맞춰 의존성(전제조건)을 체크하고 이전과 같은지 다른지를 파악하여
# 다시 rebuild 할지를 따르게 된다.
# 즉, 전과 다른 의존성의 결과를 가지지 않는다면? -> nothing to be done.

# bonus : .timestamps
# .timestamps: $(OBJS_BONUS)
# 		touch .timestamps
# 		ar rcs $(NAME) $(OBJS_BONUS)

# 근데 이렇게 해주는건 바로 .timestamps의 의존성이 이전과 같은지를 확인하고 그게 같다면 bonus는 .phony에 있어도 nothing to be done이 된다.
# .timestamps명령어 이름과 touch .timestamps 과 같이 해줘야 하는것은 
# => 명령어와 같은 이름의 파일이 존재해야 존재한다고 생각하고 그 이후에 의존성을 ($(OBJS_BONUS))체크해서 이전과 다른게 있는지 파악한 다음에
# 결국, 파일이 이미 존재하고 timestamps를 체크했을때 이전과 같은결과를 갖고 있어 rebuil가 안되게 만드는것.

# 그리고 .을 해주는건 hidden file로 만들어서 좀더 보기에 이쁘게 만드려고 한것...ㅎㅎ