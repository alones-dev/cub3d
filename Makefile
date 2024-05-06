### PROGRAM NAME ###
NAME		:= cub3D

### UTILS ###
CC 			:= clang
CFLAGS 		:= -Wall -Wextra -Werror -g3
DEP_FLAGS	:= -MMD -MP
MAKE_FLAG 	:= --no-print-directory --silent
RM 			:= rm -rf

### COLORS ###
DEFAULT    	:= \033[0m
BLACK    	:= \033[0;30m
RED        	:= \033[0;31m
GREEN    	:= \033[0;32m
UGREEN    	:= \033[4;32m
YELLOW    	:= \033[;33m
BLUE    	:= \033[0;34m
PURPLE    	:= \033[0;35m
CYAN    	:= \033[0;36m
BWHITE    	:= \033[1;37m
NEW			:= \r\033[K

### DIRECTORIES ###
SRC_DIR 	:= src
INCLD_DIR 	:= include
OBJS_DIR 	:= objs
LIBFT_DIR 	:= libft
MLX_DIR 	:= mlx

### FILES ###
define INCLUDES	:=
	$(INCLD_DIR)/
	$(LIBFT_DIR)/
	$(MLX_DIR)/
endef
INCLUDES 	:= $(strip $(INCLUDES))

INCLD_FLAG 	:= $(addprefix -I , $(INCLUDES))
LIBFT		:= $(LIBFT_DIR)/libft.a
MLX			:= $(MLX_DIR)/libmlx.a

define LIB 	:=
	$(LIBFT)
	$(MLX)
	-lXext -lX11 -lm
endef
LIB 		:= $(strip $(LIB))

define SRC :=
	colors.c
	main.c
	map.c
	utils.c
	utils2.c
	parsing.c
	movement.c
	ray_cast.c
	mini_map.c
	put_element.c
	init_mvt.c
	init_value.c
	init_txt.c
	check_map.c
	utils_parsing.c
	free_txt.c
endef
SRC 		:= $(strip $(SRC))

OBJS 		:= $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRC))
DEPS		:= $(patsubst %.c,$(OBJS_DIR)/%.d,$(SRC))

### PROJECT ###
.PHONY: all
all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	@printf "$(NEW)$(PURPLE)[$(JP)] $(UGREEN)Building:$(DEFAULT)$(BWHITE) $@$(DEFAULT)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) $(INCLD_FLAG) -o $@
	@printf "\n"

-include $(DEPS)
$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@printf "$(NEW)$(PURPLE)[$(JP)] $(UGREEN)Building:$(DEFAULT) $<"
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/$(EXEC_DIR)
	@mkdir -p $(OBJS_DIR)/$(ENV_DIR)
	@mkdir -p $(OBJS_DIR)/$(BUILTIN_DIR)
	@mkdir -p $(OBJS_DIR)/$(UTILS_DIR)
	@mkdir -p $(OBJS_DIR)/$(PARSING_DIR)
	@$(CC) $(DEP_FLAGS) $(CFLAGS) $(INCLD_FLAG) -c $< -o $@

.PHONY: clean
clean: ; @printf "$(PURPLE)[$(JP)] $(RED)Removing $(DEFAULT)$(OBJS_DIR) files\n"
	@$(RM) $(OBJS_DIR)

.PHONY: fclean
fclean: clean ; @printf "$(PURPLE)[$(JP)] $(RED)Removing $(DEFAULT)$(NAME)\n"
	@$(RM) $(NAME) 

.PHONY: re
re: fclean all

### LIBFT ###
$(LIBFT):
	@make -C $(LIBFT_DIR) $(MAKE_FLAG)

.PHONY: cleanlib
cleanlib: ; @make -C $(LIBFT_DIR) clean $(MAKE_FLAG)

.PHONY: fcleanlib
fcleanlib: ; @make -C $(LIBFT_DIR) fclean $(MAKE_FLAG)

.PHONY: relib
relib: ; @make -C $(LIBFT_DIR) re $(MAKE_FLAG)

### MLX ###
$(MLX):
	@make -C $(MLX_DIR) $(MAKE_FLAG)

.PHONY: cleanlib
cleanmlx: ; @make -C $(MLX_DIR) clean $(MAKE_FLAG)
