NAME		= cub3D

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -Ilibft -Ignl -Isrc/parser/utils -Isrc/cleanup -Iminilibx -I.

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

MLX_DIR		= minilibx
MLX			= $(MLX_DIR)/libmlx.a

GNL_DIR		= gnl
GNL_SRCS	= $(GNL_DIR)/get_next_line.c

UTILS_SRCS	= src/parser/utils/parse_map_utils.c \
			  src/parser/utils/read_map_lines.c \
			  src/parser/utils/calculate_map_width.c \
			  src/parser/utils/store_map.c

VALID_SRCS	= src/parser/validation/map_validation.c \
			  src/parser/validation/map_flood_fill.c

CLEANUP_SRCS= src/cleanup/free_map.c \
			  src/cleanup/free_game.c

SRCS		= main.c \
			  src/utils/error.c \
			  src/init/init_game.c \
			  src/init/init_mlx.c \
			  src/init/init_player.c \
			  src/init/load_textures.c \
			  src/game/movement.c \
			  src/game/rotation.c \
			  src/render/render.c \
			  src/render/raycaster.c \
			  src/render/background.c \
			  src/parser/parser.c \
			  src/parser/read_file.c \
			  src/parser/parse_texture.c \
			  src/parser/parse_texture_utils.c \
			  src/parser/parse_color.c \
			  src/parser/parse_map.c \
			  $(UTILS_SRCS) \
			  $(VALID_SRCS) \
			  $(GNL_SRCS) \
			  $(CLEANUP_SRCS)

OBJ_DIR		= obj
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(MLX_DIR)/libmlx.a

re: fclean all

norm:
	norminette main.c cub3d.h src/utils/error.c src/init/init_game.c \
	src/init/init_mlx.c src/init/init_player.c src/init/load_textures.c \
	src/game/movement.c src/game/rotation.c \
	src/render/render.c src/render/raycaster.c src/render/background.c \
	src/parser/parser.c src/parser/read_file.c src/parser/parse_texture.c \
	src/parser/parse_texture_utils.c src/parser/parse_color.c \
	src/parser/parse_map.c \
	src/parser/validation/map_validation.c src/parser/validation/map_flood_fill.c \
	src/parser/utils/parse_map_utils.c src/parser/utils/parse_map_utils.h \
	src/parser/utils/read_map_lines.c \
	src/parser/utils/calculate_map_width.c src/parser/utils/store_map.c \
	src/cleanup/free_map.c src/cleanup/free_game.c \
	gnl/get_next_line.c gnl/get_next_line.h \
	libft/*.c libft/libft.h

.PHONY: all clean fclean re norm
