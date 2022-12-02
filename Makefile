NAME = cub3d

VPATH = src:\
		src/parser\
		src/top_view

HEADER = inc/

CFLAGS = -I include 

LFLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

CC = gcc
# -Wall -Werror -Wextra
LIBFT = lib/libft/libft.a
MLX = lib/mlx/libmlx42.a

OBJS_DIR = objs
SRC_DIR = src

# INC	:=	-I $(INCLUDE_DIR)
INC = -Ilibft -Iinc -I

SRCS =	main.c \
		cub3d.c \
		hook.c \
		draw_wall.c \
		init_data.c \
		raycast.c\
		parser/check_input.c

OBJS =	$(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

ifdef DEBUG
 CFLAGS = -Wextra -Wall -Werror -fsanitize=undefined -g
 LIBFT_MAKE = make debug -sC lib/libft
else
 CFLAGS = -Wextra -Wall -Werror -g
 LIBFT_MAKE = make -sC lib/libft
endif

all: $(LIBFT) $(MLX) $(NAME)

debug:
	@$(MAKE) DEBUG=1 all

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -I -c -o $@ $<

$(LIBFT):
	@$(LIBFT_MAKE)

$(MLX):
	@$(MAKE) -C lib/mlx 

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(INC) -I $^ -o $(NAME) $(LFLAGS)
	@echo "\033[92mFiles made\033[0m"

clean:
	@rm -rf $(OBJS_DIR)
	@make clean -C lib/libft
	@rm -f libmlx.dylib
	@echo "\033[1;34mA\033[1;31ml\033[1;32ml \033[1;33mc\033[1;30ml\033[1;35me\033[1;36ma\033[1;37mn\033[0m"

fclean:
	@rm -rf $(OBJS_DIR)
	@rm -f $(NAME)
	@rm -f $(MLX)
	@make fclean -C lib/libft
	@echo "\033[0;31mFiles cleaned\033[0m"

re: fclean all

.PHONY: all clean fclean re