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

NAME = zombie

CC		= g++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf
SRC		= main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
OBJ		= $(SRC:.cpp=.o)

GREEN       =   \033[1;32m
YELLOW      =   \033[1;33m
RED 		=   \033[1;31m
NO_COLOR    =   \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(YELLOW)- Compiling $(NAME)... $(NO_COLOR)\n"
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@printf "$(GREEN)- Executable ready\n$(NO_COLOR)"

clean:
	@$(RM) $(OBJ)
	@printf "$(RED)- Objects removed$(NO_COLOR)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(YELLOW)- Executable removed$(NO_COLOR)\n"

re: clean all

.PHONY: all clean re fclean
