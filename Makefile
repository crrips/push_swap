NAME = push_swap
CHECKER = checker

SRC = 	mandatory/push_swap.c \
		mandatory/utils/creating.c		mandatory/utils/errors.c	mandatory/utils/my_math.c	\
		mandatory/utils/push.c			mandatory/utils/rev_rot.c	mandatory/utils/rotate.c	\
		mandatory/utils/s1mple_sort.c	mandatory/utils/sort.c		mandatory/utils/swap.c		\
		mandatory/utils/utils4stacks.c
OBJ = $(SRC:.c=.o)

SRC_B = bonus/checker_bonus.c \
		bonus/utils/creating.c			bonus/utils/errors.c		bonus/utils/push.c			\
		bonus/utils/rev_rot.c			bonus/utils/rotate.c		bonus/utils/swap.c			\
		bonus/utils/utils4stacks.c		bonus/utils/get_next_line.c	bonus/utils/get_next_line_utils.c
OBJ_B = $(SRC_B:.c=.o)

FLAGS = -Wall -Werror -Wextra -g3
INC = -I libft

HEADERS = mandatory/push_swap.h
HEADERS_B = bonus/push_swap.h

RED 	= \033[31m
GREEN 	= \033[32m
END 	= \033[0m

%.o:%.c $(HEADERS)
	@cc $(FLAGS) $(INC) -c $< -o $@

all: $(NAME)
$(NAME):$(OBJ)
	@cd libft && $(MAKE)
	@cc $(FLAGS) $(INC) $(OBJ) libft/libft.a -o $@ 
	@echo "$(GREEN)Executable file $(NAME) was compiled!$(END)"

bonus: $(CHECKER)
$(CHECKER):$(OBJ_B)
	@cd libft && $(MAKE)
	@cc $(FLAGS) $(INC) $(OBJ_B) libft/libft.a -o $@ 
	@echo "$(GREEN)Executable file $(CHECKER) was compiled!$(END)"

clean:
	@cd libft && $(MAKE) fclean
	@rm -f $(OBJ) $(OBJ_B)
	@echo "$(RED)Object files was deleted!$(END)"
	
fclean: clean
	@rm -f $(NAME) $(CHECKER)
	@echo "$(RED)Executable file(s) was deleted!$(END)"

re:	fclean all
	@echo "$(GREEN)Project was reloaded!$(END)"

.PHONY: all clean fclean re bonus