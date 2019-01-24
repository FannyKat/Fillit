NAME			= fillit
CFLAGS			= -Wall -Wextra -Werror -I include/.

LIB_PATH		=	libft
LIB				=	$(LIB_PATH)/libft.a

SRC				= src/init.c src/check.c src/map.c src/normalize.c \
				  src/solve.c src/to_resolve.c

OBJ				= $(SRC:.c=.o)

CC				= gcc

all:			$(NAME)

$(NAME): 		$(OBJ)
				@make -C $(LIB_PATH)
				@$(CC) $(CFLAGS) $(SRC) $(LIB) -o $(NAME)

clean:
				@rm -f $(OBJ)
				@make -C $(LIB_PATH) clean

fclean: 		clean
				@rm -f $(NAME)
				@make -C $(LIB_PATH) fclean

re: 			fclean all

.PHONY: 		all clean fclean re
