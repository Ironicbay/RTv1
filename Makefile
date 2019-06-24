# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/11 14:38:52 by acostaz           #+#    #+#              #
#    Updated: 2019/06/19 16:02:09 by acostaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -MMD

ifeq ($(DEBUG),yes)
	$(CFLAGS) += -g -DDEBUG #-fsanitize=address
else
	$(CFLAGS) += -O2 -flto -march=native
endif

NAME = rtv1

MLX = mlx/libmlx.a
LIBFT = libft/libft.a
FRAMEWORK = -framework OpenGL -framework AppKit

SRC_NAME =	main.c				\
			make_everything.c	\
			math_vector.c		\
			math2.c				\
			math_base.c			\
			intersections.c		\
			parsing.c			\
			parsing_shapes.c	\
			parsing_utils.c		\
			default_shapes.c	\
			list.c				\
			ray.c				\
			lights.c			\
			passerelle.c		\
			util.c				\
			image_utils.c		\
			get_normal.c		\
			move.c				\
			material.c			\
			material1.c			\
			material2.c			\
			material3.c			\
			material4.c			\
			material5.c			

SRC_DIR = src
BUILD_DIR = obj
INC_DIR = inc

OBJ = $(addprefix $(BUILD_DIR)/,$(SRC_NAME:.c=.o))
DPD = $(addprefix $(BUILD_DIR)/,$(SRC_NAME:.c=.d))

opti:
	@$(MAKE) -j all

debug:
	@$(MAKE) opti DEBUG=yes

all:
	@$(MAKE) all -C libft
	@$(MAKE) all -C mlx
	@$(MAKE) $(NAME)

$(NAME): $(OBJ)
	@echo "\033[2K \033[A"
	@gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(FRAMEWORK) $(MLX)
	@echo "\033[32m[$(NAME)]: compiled\033[0m"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(MLX) $(LIBFT)
	@mkdir -p $(BUILD_DIR)
	@echo "\033[2K [$(NAME)]: Compilation of $< \033[A"
	@gcc $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@$(MAKE) clean -C libft
	@$(MAKE) clean -C mlx
	@rm -rf $(BUILD_DIR)
	@echo "\033[33m[$(NAME)]: OBJ deleted\033[0m"

fclean: clean
	@rm -f $(LIBFT)
	@echo "\033[31m[$(LIBFT)]: deleted\033[0m"
	@rm -f $(MLX)
	@echo "\033[31m[$(MLX)]: deleted\033[0m"
	@rm -f $(NAME)
	@echo "\033[31m[$(NAME)]: deleted\033[0m"

re : fclean all

.PHONY: all, clean, fclean, re

-include $(DPD)
