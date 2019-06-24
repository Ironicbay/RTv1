# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/11 16:13:34 by acostaz           #+#    #+#              #
#    Updated: 2019/05/10 12:15:49 by acostaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmlx.a
SRC_NAME = mlx_shaders.c \
	 	   mlx_new_window.m \
	 	   mlx_init_loop.m \
	 	   mlx_new_image.m \
	 	   mlx_xpm.c \
	 	   mlx_int_str_to_wordtab.c

CFLAGS+=-O2

SRC_DIR = src
BUILD_DIR = obj
INC_DIR = inc

OBJ1 = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(BUILD_DIR)/,$(OBJ1:.m=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[2K \033[A"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32m[$(NAME)]: compiled\033[0m"

#ar -r

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.[cm]
	@mkdir -p $(BUILD_DIR)
	@echo "\033[2K [$(NAME)]: Compilation of $< \033[A"
	@gcc $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@rm -f $(OBJ) *~
	@rm -f mlx_app
	@echo "\033[33m[$(NAME)]: OBJ deleted\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m[$(NAME)]: deleted\033[0m"

re: fclean all
