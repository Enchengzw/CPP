# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 16:38:50 by ezhou             #+#    #+#              #
#    Updated: 2024/08/29 17:22:13 by ezhou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOUR_=\033[0;32m
COLOUR_=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

NAME = Bureaucrat

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC	= main.cpp Bureaucrat.cpp Cat.cpp Dog.cpp WrongBureaucrat.cpp WrongCat.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(COLOUR_)(•̀ᴗ•́)و $(NAME) generado!$(COLOUR_END)"

%.o : %.cpp
	@$(CC) $(CFLAGS) -I./$(INCLUDE) -c -o $@ $<
	@echo "$(COLOUR_BLUE)(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compilando archivos .cpp$(COLOUR_END)"

norm:
	@norminette $(SRC) $(INCLUDE)*.h

clean:
	@$(RM) $(OBJ)
	@echo "$(COLOUR_)¯\_(ツ)_/¯ Objetos removidos!$(COLOUR_END)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(COLOUR_)(╯°□°）╯︵ ┻━┻ $(NAME) removido!$(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re norm
