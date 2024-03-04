/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:28:44 by ageiser           #+#    #+#             */
/*   Updated: 2024/02/27 18:28:46 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook annuaire; //Create an instance of the PhoneBook class    
    std::string line; //Create a string variable called line
  
    while(line != "EXIT")
    {
        std::cout << "$> ";
        std::getline(std::cin, line);
        if (line == "ADD")
        {
            std::cout << "ADD" << std::endl;
            annuaire.add();
        }
        else if (line == "SEARCH")
        {
            std::cout << "SEARCH" << std::endl;
            annuaire.search();
        }
        if (std::cin.eof())
        {
            std::cout << std::endl;
            return (0);
        }
    }
    return (0);
}