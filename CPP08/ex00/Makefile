# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 16:38:50 by ezhou             #+#    #+#              #
#    Updated: 2024/09/05 16:55:08 by ezhou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

NAME = easyfind

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC	= Main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(COLOUR_GREEN)(•̀ᴗ•́)و $(NAME) generado!$(COLOUR_END)"

%.o : %.cpp
	@$(CC) $(CFLAGS) -I./$(INCLUDE) -c -o $@ $<
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
