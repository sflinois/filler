# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/10 11:48:48 by sflinois          #+#    #+#              #
#    Updated: 2017/05/24 15:38:17 by sflinois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

CCRED =	"\033[0;31m"
CCYELLOW = "\033[0;33m"
CCGREEN = "\033[0;32m"
CCEND = "\033[0m"

SRC_PATH = src
SRC_NAME = check_error.c filler.c init_struct.c parsing.c resolve_map.c territory.c
OBJ_PATH = objs
CPPFLAGS = -Iincludes

LDLIBS = lib/libft.a
FRAM = -framework OpenGL -framework AppKit

NAME = sflinois.filler

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $(LDLIBS) $(OBJ) $(FRAM)
	@echo $(CCGREEN) filler OK $(CCEND)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@echo $(CCRED)
	@rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo $(CCEND)

fclean: clean
	@echo $(CCRED)
	@rm -fv $(NAME)
	@echo $(CCEND)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h
