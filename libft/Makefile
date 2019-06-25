# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/11 16:13:36 by acostaz           #+#    #+#              #
#    Updated: 2019/06/25 13:29:18 by acostaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -MMD

ifeq ($(DEBUG),yes)
	$(CFLAGS) += -g -DDEBUG #-fsanitize=address
else
	$(CFLAGS) += -O2 -flto -march=native
endif

NAME = libft.a

SRC_NAME = ft_bzero.c \
		   ft_error.c \
		   ft_putchar.c \
		   ft_putendl.c \
		   ft_putendl_fd.c \
		   ft_putnbr.c \
		   ft_putnbrendl.c \
		   ft_putstr.c \
		   ft_strcmp.c \
		   ft_strlen.c \
		   ft_atoi.c \
		   ft_atof.c \
		   ft_strequ.c \
		   get_next_line.c \
		   ft_strchr.c \
		   ft_strclr.c \
		   ft_strdel.c \
		   ft_strjoin.c \
		   ft_strncpy.c \
		   ft_strnew.c \
		   ft_strnequ.c

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
	@$(MAKE) $(NAME)

$(NAME): $(OBJ) $(INC_DIR)/libft.h $(INC_DIR)/get_next_line.h
	@echo "\033[2K \033[A"
	@ar rc $(NAME) $(OBJ)
	@echo "\033[32m[$(NAME)]: compiled\033[0m"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	@echo "\033[2K [$(NAME)]: Compilation of $< \033[A"
	@gcc $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR)
	@echo "\033[33m[$(NAME)]: OBJ deleted\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m[$(NAME)]: deleted\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re

-include $(DPD)
