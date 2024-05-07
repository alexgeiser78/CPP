# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 18:29:02 by ageiser           #+#    #+#              #
#    Updated: 2024/02/27 18:29:06 by ageiser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98 #-fsanitize=address -fsanitize=undefined -fsanitize=bounds -fsanitize=null #-fsanitize=leak
RM		= rm -rf
SRC		= main.cpp Fixed.cpp
OBJ		= $(SRC:.cpp=.o)

GREEN       =   \033[1;32m
YELLOW      =   \033[1;33m
RED 		=   \033[1;31m
NO_COLOR    =   \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)- Compiling $(NAME)... $(NO_COLOR)"
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)- Executable ready$(NO_COLOR)"

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo "$(RED)- Objects removed$(NO_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)- Executable removed$(NO_COLOR)"

re: clean all

-include $(DEP)

.PHONY: all clean re fclean
