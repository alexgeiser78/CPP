/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:42:53 by ageiser           #+#    #+#             */
/*   Updated: 2024/04/17 19:42:55 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Hi, my name is Harl!" << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "Harl is gone!" << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]   ";
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger.";
	std::cout << " I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]    ";
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << " You didn't put enough bacon in my burger! If you did, I wouldn't be asking";
	std::cout << " for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING] ";
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << " I've been coming for years whereas you started ";
	std::cout << "working here last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]   ";
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}

void	Harl::complain(std::string level)
{
    void		(Harl::*ptr_complain[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error}; //tab declaration of 4 pointers to functions
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"}; //tab declaration of 4 strings
    int i;

    i = 0;
    while(i < 4)
	{
		if (levels[i] == level) //if one of levels[i] is equal to level passed as argument in the function
		{
			(this->*ptr_complain[i])(); //call the function pointed by ptr_complain[i]
			break ;
		}
        i++;
	}

}
