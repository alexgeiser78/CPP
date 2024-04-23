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

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98 -MD
RM		= rm -rf
SRC		= main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
OBJ		= $(SRC:%.cpp=%.o)
DEP		= $(SRC:%.cpp=%.d)

GREEN       =   \033[1;32m
YELLOW      =   \033[1;33m
RED 		=   \033[1;31m
NO_COLOR    =   \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(YELLOW)- Compiling $(NAME)... $(NO_COLOR)\n"
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(OBJ)
	@printf "$(GREEN)- Executable ready\n$(NO_COLOR)"

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@$(RM) $(DEP)
	@printf "$(RED)- Objects removed$(NO_COLOR)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(YELLOW)- Executable removed$(NO_COLOR)\n"

re: clean all

-include $(DEP)

.PHONY: all clean re fclean
