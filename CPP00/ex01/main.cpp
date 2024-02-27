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
    std::string line;

    std::cout << "$> ";

    std::getline(std::cin, line);
    if (line == "ADD")
        std::cout << "ADD" << std::endl;
    else if (line == "SEARCH")
        std::cout << "SEARCH" << std::endl;
    else if (line == "EXIT")
        std::cout << "EXIT" << std::endl;

    return (0);
}