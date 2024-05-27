# Compiler and compiler flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Ofast
SRC = fractol.c fractal_sets.c key_handlers.c mouse_handlers.c
BUILD_DIR = ./build

# LIBS
LIBS_PATH = ./libs

# Minilibx
MLX_NAME   = MiniLibX
MLX_PATH	= $(LIBS_PATH)/minilibx_opengl
MLX_LINK	= -L${MLX_PATH} -lmlx -framework OpenGL -framework AppKit

# Libft
LIBFT_NAME = libft
LIBFT_PATH 	= $(LIBS_PATH)/libft
LIBFT_LINK	= -L${LIBFT_PATH} -lft


OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)
DPS := $(SRC:%.c=$(BUILD_DIR)/%.d) 

PREQ = Makefile 
NAME = fractol
DEFLAGS := -MMD -MP

#Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m

# Functions
define make_lib
    @echo "Making $1..."
    @make -C $2 
    @echo "$(GREEN)📚completed		$1$(DEF_COLOR)"
endef

all: make_libs $(NAME)

make_libs:
	$(call make_lib,$(MLX_NAME),$(MLX_PATH))
	$(call make_lib,$(LIBFT_NAME),$(LIBFT_PATH))

$(NAME): $(OBJ) ${LIBFT_PATH}/libft.a
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_LINK) $(LIBFT_LINK)
	@echo "$(GREEN)📚completed		$(NAME)$(DEF_COLOR)"

$(BUILD_DIR)/%.o: %.c $(PREQ) | $(BUILD_DIR) 
	@$(CC) $(CFLAGS) $(DEFLAGS) -c $< -o $@
	@echo "$(GRAY)⏳compiling		$<$(DEF_COLOR)"
	
$(BUILD_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(BUILD_DIR)
	@Make -C $(MLX_PATH) clean
	@Make -C $(LIBFT_PATH) clean
	@echo "$(RED)🧹clean		${NAME}$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)

re: fclean all

-include $(DPS)

.PHONY: re fclean clean all make_libs