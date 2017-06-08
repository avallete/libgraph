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
SRC_NAME:= delete_matrice_graph.c\
           get_link.c\
           invert_link.c\
           negate_link.c\
           new_matrice_graph.c\
           set_link.c\
           toggle_link.c\
           unset_link.c\
           new_path.c\
           new_pathfind.c\
           delete_path.c\
           delete_pathfind.c\
           pathfind_to_path.c\
           graph_to_paths.c\
           add_path_to_graph.c\
           bellman_ford.c\
           dijkstra.c\
           bhandari.c

INC_PATH=./includes/
INC_NAME=libmatgraph.h

OBJ_PATH=./obj/
OBJ_NAME=$(SRC_NAME:.c=.o)

SRC=$(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ=$(addprefix $(OBJ_PATH), $(OBJ_NAME))
INCF=$(addprefix $(INC_PATH), $(INC_NAME))
INC=$(addprefix -I, $(INC_PATH))

SRC=$(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ=$(addprefix $(OBJ_PATH), $(OBJ_NAME))
INCF=$(addprefix $(INC_PATH), $(INC_NAME))
INC=$(addprefix -I, $(INC_PATH))
CFLAGS=-Wall -Wextra -Werror
CC=gcc
NAME=libgraph.a
RED=\033[0;31m
LBLUE=\033[34m
GREEN=\033[32m
CYAN=\033[0;36m
ORANGE=\033[0;33m
NC=\033[0m


all: $(NAME)

$(NAME):$(OBJ)
	@echo "${GREEN}Compile $(NAME) with $(CFLAGS)${NC}";
	@echo "${LBLUE}ar rc $(NAME)${NC}"
	@ar rc $(NAME) $(OBJ)
	@echo "${ORANGE}ranlib $(NAME)${NC}"
	@ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@echo "${ORANGE}Create bynary $(NAME) : $@ with $<${NC}";
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@echo "${RED}Delete OBJ files${NC}"
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo "${RED}Delete $(NAME) file${NC}"
	@rm -rf $(NAME)

debug: CFLAGS=-g3 -O0
debug: all

re: fclean all clean

.PHONY: all clean fclean re

