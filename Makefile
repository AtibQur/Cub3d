NAME = cub3d

HEADER = inc/

CFLAGS = -g -I include 

LFLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

CC = gcc
# -Wall -Werror -Wextra
LIBFT = lib/libft/libft.a
MLX = lib/mlx/libmlx42.a

OBJS_DIR = objs
SRC_DIR = src

INC	:=	-I $(INCLUDE_DIR)

SRCS =	main.c \
		cub3d.c \
		check_input.c \
		draw_wall.c \
		top_view.c \
		hook.c \
		init_data.c \
		parse_map.c \

OBJS =	$(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

all: $(LIBFT) $(MLX) $(NAME)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -I -c -o $@ $<

$(LIBFT):
	$(MAKE) -C lib/libft

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