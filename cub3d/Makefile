NAME = ./cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
MLX = exec/mlx/libmlx.a exec/mlx/libmlx_Linux.a
MLXFLAGS = -lX11 -lXext -lm

SRC = main.c						\
	free.c							\
	init_parsing.c					\
	checks_parsing/parsing_errors.c	\
	checks_parsing/check_dups.c		\
	checks_parsing/check_below.c	\
	checks_parsing/check_unknown.c	\
	checks_parsing/check_textures.c	\
	checks_parsing/check_colors.c	\
	grab_info/grab_info.c			\
	grab_info/get_map.c				\
	grab_info/get_spawn.c			\
	grab_info/decrypt_colors.c		\
	grab_info/grab_colors.c			\
	grab_info/grab_textures.c		\
	grab_info/flood_fill.c			\
	exec/cast_utils.c				\
	exec/cast.c						\
	exec/inputs.c					\
	exec/raycasting.c

OBJET = $(SRC:.c=.o)
LIBFT = ./big_ft/libft.a
#EXEC = ./exec

all: $(NAME)

$(LIBFT):
	make --no-print-directory -C ./big_ft

#$(EXEC):
#	make --no-print-directory -C ./exec

$(NAME): $(OBJET) $(LIBFT) $(EXEC)
	$(CC) $(CFLAGS) $(OBJET) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)

clean:
	rm -f $(OBJET)
	make clean --no-print-directory -C ./big_ft

fclean: clean
	rm -f $(NAME)
	make fclean --no-print-directory -C ./big_ft

re: fclean all

.PHONY: all clean fclean re
