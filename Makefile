# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avallete <avallete@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/18 13:18:20 by avallete          #+#    #+#              #
#*   Updated: 2016/08/06 03:56:22 by avallete         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

CFLAGS=-Wall -Wextra -Werror

SRC_PATH:=./src/
SRC_NAME:=	main.c
INC_PATH=./includes/
INC_NAME=libft.h

OBJ_PATH=./obj/
OBJ_NAME=$(SRC_NAME:.c=.o)

SRC=$(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ=$(addprefix $(OBJ_PATH), $(OBJ_NAME))
INCF=$(addprefix $(INC_PATH), $(INC_NAME))
INC=$(addprefix -I, $(INC_PATH))

LIBFT:=-L libft/ -lft
CC=clang
NAME=lem_in
RED=\033[30;41m
GREEN=\033[32m
CYAN=\033[36m
ORANGE=\033[33m
NC=\033[0m

all: $(NAME)

$(NAME):$(OBJ)
	@make -s -C libft
	@echo "${GREEN}Compile $(NAME) with $(CFLAGS)${NC}";
	@$(CC) $(CLFAGS) $(OBJ) $(INC) $(LIBFT) -o $(NAME)

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@echo "${ORANGE}Create bynary $(NAME) : $@ with $<${NC}";
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@echo "${RED} Delete OBJ files ${NC}"
	@make clean -s -C libft
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo "${RED} Delete $(NAME) file ${NC}"
	@make fclean -s -C libft
	@rm -rf $(NAME)

noflags: CFLAGS=""
noflags: all

debug: CFLAGS=-g3 -O0
debug: all

re: fclean all clean

.PHONY: all clean fclean re debug noflags
