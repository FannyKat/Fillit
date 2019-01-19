NAME			= fillit
FLAGS			+= -Wall -Wextra

LIB_PATH		=	libft
LIB			=	$(LIB_PATH)/libft.a
LIB_LINK		=	-L $(LIB_PATH) -lft

INC_DIR			= include
INC			= -I $(LIB_PATH) -I $(INC_DIR)

SRC_DIR			= src
SRC			= init.c check.c map.c normalize.c solve.c to_resolve.c 
SRCS			= $(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR			= obj
OBJS			= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CLEAR			= \033[2K
NOCOLOR			= \033[0m
YELLOW			= \033[1;33m
BLUE			= \033[1;34m

all: obj $(NAME)

$(NAME): $(LIB) $(OBJS)
	@gcc $(FLAGS) -o $@ $^ $(LIB_LINK)
	@echo "[$(YELLOW) $(NAME) $(NOCOLOR)]"

$(LIB):
	@make -C $(LIB_PATH)
obj:
	@mkdir -p obj

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/*.h
	@gcc $(FLAGS) $(INC) -c -o $@ $<
	@echo "[$(YELLOW) $< $(NOCOLOR)]"

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo -e "$(CLEAR)$(BLUE)Clean fillit_obj$(NOCOLOR)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@echo -e "$(CLEAR)$(BLUE)Clean fillit$(NOCOLOR)"

re: fclean all

.PHONY: all clean fclean re
