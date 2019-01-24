NAME		= libft.a

FLAGS		= -Wall -Werror -Wextra -I. -c

SRCS		= ft_strlen.c ft_putendl.c ft_putendl_fd.c ft_putchar_fd.c\
				ft_putstr_fd.c ft_putchar.c ft_strdup.c\

OBJ			= $(SRCS:.c=.o)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

all: $(NAME)

$(OBJ): $(SRCS)
	gcc $(FLAGS) $(SRCS)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
