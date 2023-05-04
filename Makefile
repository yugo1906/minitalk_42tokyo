NAME				=	$(CLIENT_NAME) $(SERVER_NAME)
CLIENT_NAME = client
SERVER_NAME	=	server
CFLAGS			=	-Wall -Wextra -Werror
LIBFT_DIR		=	./include_libft
PRINTF_DIR	=	./include_ft_printf
SRC_DIR			=	./src
CLIENT_SRC	= client.c error_check_utils.c
SERVER_SRC	= server.c error_check_utils.c
CLIENT_SRCS	:= $(addprefix $(SRC_DIR)/, $(CLIENT_SRC))
SERVER_SRCS	:= $(addprefix $(SRC_DIR)/, $(SERVER_SRC))
CLIENT_OBJS	= ${CLIENT_SRCS:%.c=%.o}
SERVER_OBJS	= ${SERVER_SRCS:%.c=%.o}

all : $(NAME)

bonus : $(NAME)

$(CLIENT_NAME) : $(CLIENT_OBJS) minitalk.h
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	cc $(CFLAGS) \
	$(CLIENT_OBJS) $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a -o $@

$(SERVER_NAME) : $(SERVER_OBJS) minitalk.h
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	cc $(CFLAGS) \
	$(SERVER_OBJS) $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a -o $@

clean :
		make clean -C $(LIBFT_DIR)
		make clean -C $(PRINTF_DIR)
		rm -f $(CLIENT_OBJS) $(SERVER_OBJS)

fclean : clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)
	rm -f $(NAME)

re: fclean all

sanitize: CFLAGS += -g -fsanitize=address
sanitize: re

.PHONY: all clean fclean re sanitize bonus