# -------------------------------------------------- #
# 					VARIABLES						 #
# -------------------------------------------------- #

NAME		:=	miniRT

SRC_DIR		:=	srcs
GW_DIR		:=	graphical_window
PARSING_DIR	:=	parsing
UTILS_DIR	:=	utils
PRINT_DIR	:=	$(UTILS_DIR)/prints
OBJ_DIR		:=	.obj

SRCS	:=	main.c \
			$(addprefix $(PRINT_DIR)/,					term_write_funcs.c print_p_attributes.c print_scene.c print_intersect.c print_matrix.c) \
			$(addprefix $(GW_DIR)/,						key_hook.c mainwindow.c create_image.c close_window.c put_one_pixel.c angle.c move.c step.c angle_z.c) \
			$(addprefix $(PARSING_DIR)/, $(addprefix	checks_map/, verify_all.c verify_map.c check_maj.c check_min.c different_tests.c check_unfloat.c) \
										 $(addprefix	fill_scene/, basic_fill_funcs.c fill_maj.c fill_min.c fill_scene.c cam_view_transform.c)) \
			$(addprefix $(UTILS_DIR)/,					determine_n.c determine_n_u.c get_inv_transfo.c instance_matrix.c count_strs.c truncate_at.c try_values.c free_scene.c choose_apply_mat.c create_materials.c prepare_computations.c shade_hit.c color_at.c \
										$(addprefix 	object_utils/, add_object.c tranform_cam.c free_object.c new_object.c return_object.c obj_lst_size.c create_sphere.c transform_object.c  add_light.c free_lights.c container_utils.c)\
										$(addprefix 	colors/,		 make_color.c color_arithmetics.c color_point.c create_pattern.c get_pattern.c blend_color.c) \
										$(addprefix 	vectors_points/, tupple_vec_product.c tupple_math.c make_point.c make_vector.c compare_points.c points_arithmetics.c tupples_utils.c ) \
										$(addprefix 	matrices/,		 compare_matrices.c copy_sub_matrix.c get_matrix_u.c \
																		 multiply_matrices.c multiply_matrix_by_tuple.c multiply_matrix_identity.c \
																		 multiply_tuple_identity.c transpose_matrix.c invert_matrix.c inverting_matrix_u.c  \
																		 translate_matrix.c scale_matrix.c reflect_matrix.c rotate_x_matrix.c rotate_y_matrix.c rotate_z_matrix.c shearing_matrix.c) \
										$(addprefix rays/, 				 ray.c cylinder_inter.c cone_inter.c ray_intersect.c intersect_lst.c get_hit.c transform_ray.c normal_at.c reflect.c fill_l_on_obj.c refract.c))

SRC		:=	$(addprefix $(SRC_DIR)/, $(SRCS))

OBJS	:=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o) )

DEPS	:=	$(OBJS:%.o=%.d)

MAKE	:=	make #-j4#j$(nproc)
MKDIR	:=	mkdir -p
CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror -O3 -fno-builtin #-g
LDFLAGS	:=	
LDLIBS	:=	
INCS	:=	-I./includes/
RM		:=	rm -rf

TEST_SCRIPT_WRONG_MAPS	:=	script_wrong_maps.sh

# -------------------------------------------------- #
# 					COLORS							 #
# -------------------------------------------------- #

GREEN			:=	\033[1;32m
YELLOW			:=	\033[1;33m
BLUE			:=	\033[1;34m
RED				:=	\033[1;31m
BEIGE			:=	\033[1;38;5;229m
BROWN			:=	\033[0;38;5;94m
DARK_BLUE		:=	\033[0;38;5;17m
DARK_GREY		:=	\033[0;38;5;238m
RESET			:=	\033[0m
P_CLEAR_SCREEN	:=	\1\033[2J\033[1;1H\2

# -------------------------------------------------- #
# 					MLX CONFIG						 #
# -------------------------------------------------- #

MLX_NAME	:=	minilibx
MLX_DIR		:=	minilibx-linux
MLX_REPO	:=	git@github.com:42paris/minilibx-linux.git
MLX_LIB		:=	$(MLX_DIR)/libmlx.a
MLX_INC		:=	-I$(MLX_DIR)
MLX_LDFLAGS	:=	-L$(MLX_DIR)
MLX_LDLIBS	:=	-lmlx -lXext -lX11 -lm

INCS		+=	$(MLX_INC)
LDFLAGS		+=	$(MLX_LDFLAGS)
LDLIBS		+=	$(MLX_LDLIBS)

# -------------------------------------------------- #
# 					LIBFT CONFIG					 #
# -------------------------------------------------- #

LIBFT_NAME		:=	libft
LIBFT_DIR		:=	LIBFT
LIBFT_LIB		:=	$(LIBFT_DIR)/libft.a
LIBFT_INC		:=	-I$(LIBFT_DIR)
LIBFT_LDFLAGS	:=	-L$(LIBFT_DIR)
LIBFT_LDLIBS	:=	-lft

INCS			+=	$(LIBFT_INC)
LDFLAGS			+=	$(LIBFT_LDFLAGS)
LDLIBS			+=	$(LIBFT_LDLIBS)

# -------------------------------------------------- #
# 					BUILD RULES						 #
# -------------------------------------------------- #

all: $(MLX_NAME) $(LIBFT_LIB) $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@$(MKDIR) $(dir $@)
	@echo "$(BLUE)Compiling$(RESET) $<..."
	@$(CC) $(CFLAGS) $(INCS) -MMD -MP -c $< -o $@

$(MLX_LIB):
	@echo "$(YELLOW)Building $(MLX_NAME)...$(RESET)"
	@$(MAKE) -C $(MLX_DIR) --silent

$(LIBFT_LIB):
	@echo "$(YELLOW)Building $(LIBFT_NAME)...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --silent
	@echo -n "$(P_CLEAR_SCREEN)\n"
	@echo "$(GREEN)[DONE]$(RESET) $(LIBFT_NAME) successfully compiled."

$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	@echo "$(BLUE)Linking$(RESET) $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS)  -o $(NAME)
	@echo -n "$(P_CLEAR_SCREEN)\n"
	@echo "$(GREEN)[DONE]$(RESET) $(NAME) successfully compiled."

-include ${DEPS}

clean:
	@echo "$(YELLOW)Cleaning objects...$(RESET)"
	@if [ -d "$(MLX_DIR)" ]; then \
		$(MAKE) -C $(MLX_DIR) clean --silent; \
	fi
	@$(MAKE) -C $(LIBFT_DIR) clean --silent
	@$(RM) $(OBJS) $(DEPS)
	@$(RM) $(OBJ_DIR)
	@echo "$(GREEN)[DONE]$(RESET) Object files cleaned."

fclean: clean
	@echo "$(YELLOW)Removing $(NAME)...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) fclean --silent
	@$(RM) $(NAME)
	@if [ -d "$(MLX_DIR)" ]; then \
		echo "$(RED)Deleting MiniLibX folder...$(RESET)"; \
		$(RM) $(MLX_DIR); \
	fi
	@echo "$(GREEN)[DONE]$(RESET) Full clean complete."

re: fclean all
	@echo "$(BLUE)Rebuilding project...$(RESET)"
	@echo "$(GREEN)[DONE]$(RESET) Rebuild complete."

$(MLX_DIR):
	@echo "$(DARK_GREY)Cloning MiniLibX...$(RESET)"
	@echo -n "$(DARK_GREY)"
	@git clone $(MLX_REPO) $(MLX_DIR)
	@echo -n "$(RESET)"
	@echo "$(YELLOW)Configuring and compiling MiniLibX...$(RESET)"
	@cd $(MLX_DIR) && ./configure
	@echo "$(GREEN)\n\n[DONE]$(RESET) $(YELLOW)MiniLibX installed and set up\n\n$(RESET)"
	@echo -n "$(P_CLEAR_SCREEN) \n"

$(MLX_NAME): $(MLX_DIR)

invalid_maps: $(NAME)
	@clear
	@if [ ! -x ./$(NAME) ]; then \
		echo "$(RED)Error: $(NAME) is not executable$(RESET)"; \
		exit 1; \
	fi
	@bash $(TEST_SCRIPT_WRONG_MAPS) ./$(NAME)

basic_test: $(NAME)
	@clear
	@if [ ! -x ./$(NAME) ]; then \
		echo "$(RED)Error: $(NAME) is not executable$(RESET)"; \
		exit 1; \
	fi
	@valgrind --leak-check=full --track-fds=yes --track-origins=yes ./$(NAME) ./scenes/default_scene.rt

cartman:
	@echo "$(YELLOW)                       _.-**-._$(RESET)"
	@echo "$(BLUE)                    _,$(YELLOW)(        )$(BLUE),_$(RESET)"
	@echo "$(BLUE)                 .-\"   $(YELLOW)'------'$(BLUE)   \"-.$(RESET)"
	@echo "$(BLUE)              .-'                    '-.$(RESET)"
	@echo "$(BLUE)            .'                          '.$(RESET)"
	@echo "$(BLUE)          .'    $(YELLOW)__.--**'\"\"\"\"\"\"'**--.__    $(BLUE)'.$(RESET)"
	@echo "$(BLUE)         /$(YELLOW)_.-*\"'__.--**'\"\"\"\"\"\"'**--.__'\"*-._$(BLUE)\\ $(RESET)"
	@echo "$(YELLOW)        /_..-*\"'   $(RESET).-*\"*-.  .-*\"*-.$(YELLOW)   '\"*-.._\\ $(RESET)"
	@echo "$(BEIGE)       :          $(RESET)/       ;:       \          $(BEIGE);		$(RED)      \"I'm not fat, I'm festively plump!\"           $(RESET)"
	@echo "$(BEIGE)       :         $(RESET):     $(DARK_BLUE)*  $(RESET)!!  $(DARK_BLUE)*     $(RESET):         $(BEIGE);$(RESET)"
	@echo "$(BEIGE)        \        $(RESET)'.     .'  '.     .'        $(BEIGE)/$(RESET)"
	@echo "$(BEIGE)         \         $(RESET)'-.-'      '-.-'         $(BEIGE)/$(RESET)"
	@echo "$(RED)      .-*''.                              .'-.$(RESET)"
	@echo "$(RED)   .-'      '.                          .'    '.$(RESET)"
	@echo "$(RED)  :           '-.        $(BEIGE)_.._$(RED)        .-'        '$(YELLOW)._$(RESET)"
	@echo "$(YELLOW) ;\"*-._          $(RED)'-._  $(DARK_BLUE)--___ $(BEIGE)\`   $(RED)_.-'        $(YELLOW)_.*'  '*.$(RESET)"
	@echo "$(YELLOW):      '.            $(RED)\`\"*-.__.-*\"\`           $(YELLOW)(         :$(RESET)"
	@echo "$(YELLOW) ;      ;                 $(DARK_BLUE)*|$(YELLOW)                 '-.     ;$(RESET)"
	@echo "$(YELLOW)  '---*'                   $(DARK_BLUE)|$(YELLOW)                    \"\"--'$(RESET)"
	@echo "$(RED)   :                      $(DARK_BLUE)*|$(RED)                      :$(RESET)"
	@echo "$(RED)   '.                      $(DARK_BLUE)|$(RED)                     .'$(RESET)"
	@echo "$(RED)     '.._                 $(DARK_BLUE)*|$(RED)        ____----.._-'$(RESET)"
	@echo "$(BROWN)      \  $(RED)\"\"\"----_____------$(DARK_BLUE)'$(RED)-----\"\"\"$(BROWN)         /$(RESET)"
	@echo "$(BROWN)       \  $(DARK_BLUE)__..-------.._        ___..---._  $(BROWN)/$(RESET)"
	@echo "$(DARK_BLUE)       :'\"              '-..--''          \"';$(RESET)"
	@echo "$(DARK_BLUE)        '\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"' '\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"'$(RESET)"


.PHONY: all clean fclean re libx invalid_maps basic_test cartman
