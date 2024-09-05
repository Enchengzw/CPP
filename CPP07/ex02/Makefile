# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: encheng <encheng@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 16:38:50 by ezhou             #+#    #+#              #
#    Updated: 2024/09/03 19:15:57 by encheng          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

NAME = Template

CC = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC	= Main.cpp
TEMPLATE_FILES = Array.tpp
OBJ = $(SRC:.cpp=.o)
INCLUDE = Include

all: $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(COLOUR_GREEN)(•̀ᴗ•́)و $(NAME) generado!$(COLOUR_END)"

%.o : %.cpp $(TEMPLATE_FILES)
	@$(CC) $(CFLAGS) -I./$(INCLUDE) -c -o $@ $< $(TEMPLATE_FILES)
	@echo "$(COLOUR_BLUE)(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compilando archivos .cpp$(COLOUR_END)"

norm:
	@norminette $(SRC) $(INCLUDE)*.h

clean:
	@$(RM) $(OBJ)
	@echo "$(COLOUR_RED)¯\_(ツ)_/¯ Objetos borrados!$(COLOUR_END)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(COLOUR_RED)(╯°□°）╯︵ ┻━┻ $(NAME) borrado!$(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re norm
