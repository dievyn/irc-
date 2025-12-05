NAME = cub3d

MAIN = raycasting.c inputs.c cast.c cast_utils.c
MLX = mlx/libmlx.a mlx/libmlx_Linux.a

OBJ = $(addprefix build/, $(MAIN:.c=.o))
OBJ_DIRS = $(sort $(dir $(OBJ)))
LIBFT = ./../big_ft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lX11 -lXext -lm
INCLUDES = -I raycasting.h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(INCLUDES) $(MLX) $(MLXFLAGS) -o $(NAME)
	@echo "\033[96m[cub3d] [✔] $(NAME) successfully compiled\033[0m"

$(LIBFT): ./../big_ft/*.c ./../big_ft/*.h
	@$(MAKE) --no-print-directory -C ../big_ft > /dev/null 2>&1
	@echo "\033[96m[minishell] [📚] Built ../big_ft library\033[0m"

build/%.o: %.c
	@mkdir -p $(OBJ_DIRS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "\033[96m[cub3d] [🔧] Compiled $<\033[0m"	

clean:
	@$(MAKE) --no-print-directory -C ../big_ft clean
	@rm -rf build
	@echo "\033[93m[cub3d] [🧹] Cleaned build directory\033[0m"

fclean:
	@rm -f $(NAME)
	@echo "\033[91m[cub3d] [🔥] Removed binary: $(NAME)\033[0m"
	@$(MAKE) --no-print-directory -C ../big_ft fclean > /dev/null 2>&1
	@rm -rf build
	@echo "\033[91m[cub3d] [🔥] Removed build directory\033[0m"
	@echo "\033[92m[cub3d] [✔] Full clean complete\033[0m"

re: 
	@$(MAKE) --no-print-directory fclean
	@$(MAKE) --no-print-directory all
	@echo "\033[94m[cub3d] [🔁] Rebuild complete\033[0m"

.PHONY: all clean fclean re

