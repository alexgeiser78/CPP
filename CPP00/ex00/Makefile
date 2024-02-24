# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/24 19:07:39 by ageiser           #+#    #+#              #
#    Updated: 2024/02/24 19:07:48 by ageiser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

GREEN       =   \033[1;32m
YELLOW      =   \033[1;33m
RED 		=   \033[1;31m
NO_COLOR    =   \033[0m

all: $(NAME)

$(NAME): 
	@printf "$(YELLOW)- Compiling $(NAME)... $(NO_COLOR)\n"
	@ $(CC) $(FLAGS) megaphone.cpp -o $(NAME)
	@printf "$(GREEN)- Executable ready.\n$(NO_COLOR)"

clean:
	@$(RM) $(NAME)
	@printf "$(RED)- Executable removed.$(NO_COLOR)\n"

fclean:
	@$(RM) $(NAME)
	@printf "$(YELLOW)- Executable removed.$(NO_COLOR)\n"

re: clean all

.PHONY: all clean re
