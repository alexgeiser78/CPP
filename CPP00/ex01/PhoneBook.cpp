/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:28:32 by ageiser           #+#    #+#             */
/*   Updated: 2024/02/27 18:28:34 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "PhoneBookUtils.hpp"


PhoneBook::PhoneBook(void)
{
    this->indux = 0; //initialize the index
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::add(void)
{
    std::string str;   //cin buffer

    str = "";
    if (this->indux > 7)
        std::cout << "Warning, user " << this->users[this->indux % 8].get_firstname() << " will be destroyed" << std::endl;
    while (!std::cin.eof() && str == "")
            {
                std::cout << "Enter first name: ";
                if (std::getline(std::cin, str) && str != "")
                    this->users[this->indux % 8].set_firstname(str);
                else
                    std::cout << "Invalid input" << std::endl;
            }
        str = "";   
        while (!std::cin.eof() && str == "")
            {
                std::cout << "Enter " << this->users[this->indux % 8].get_firstname() << " last name: ";
                if (std::getline(std::cin, str) && str != "")
                    this->users[this->indux % 8].set_lastname(str);
                else
                    std::cout << "Invalid input" << std::endl;
            }
        str = "";
        while (!std::cin.eof() && str == "")
            {
                std::cout << "Enter " << this->users[this->indux % 8].get_firstname() << " nickname: ";
                if (std::getline(std::cin, str) && str != "")
                    this->users[this->indux % 8].set_nickname(str);
                else
                    std::cout << "Invalid input" << std::endl;
            }
        str = "";
        while (!std::cin.eof() && str == "")
            {
                std::cout << "Enter " << this->users[this->indux % 8].get_firstname() << " phone number: ";
                if (std::getline(std::cin, str) && str != "")
                    this->users[this->indux % 8].set_phonenumber(str);
                else
                    std::cout << "Invalid input" << std::endl;
            }
        str = "";
        while (!std::cin.eof() && str == "")
            {
                std::cout << "Enter " << this->users[this->indux % 8].get_firstname() << " darkest secret: ";
                if (std::getline(std::cin, str) && str != "")
                {
                    this->users[this->indux % 8].set_darkestsecret(str);
                    std::cout << "User " << this->users[this->indux % 8].get_firstname() << " added [" << this->indux % 8 + 1 << "/8]" << std::endl;
                }
                else
                    std::cout << "Invalid input" << std::endl;
            }
        this->indux++; 
}


void	PhoneBook::print(Contact user)
{
    if (!user.get_firstname().length())
    {
        std::cout << "Failed to get info for this contact" << std::endl;
        return ;
    }
    std::cout << "First name: " << user.get_firstname() << std::endl;
    std::cout << "Last name: " << user.get_lastname() << std::endl;
    std::cout << "Nickname: " << user.get_nickname() << std::endl;
    std::cout << "Phone number: " << user.get_phonenumber() << std::endl;
    std::cout << "Darkest secret: " << user.get_darkestsecret() << std::endl;
}


void	PhoneBook::search(void)
{
    std::string str;   //cin buffer
    if(!search_flag(this->users))
    {
        std::cout << "No users in the phonebook" << std::endl;
        return ;
    }
    while (!std::cin.eof())
	{
		std::cout << "Select an index: ";
		if (std::getline(std::cin, str) && str != "")
		{
			if (str.length() == 1 && str[0] >= '1' && str[0] <= '8' && \
					this->users[str[0] - 1 - '0'].get_firstname().length())
				break ;
		}
		if (str != "")
			std::cout << "Invalid index!" << std::endl;
	}
	if (!std::cin.eof())
		this->print(this->users[str[0] - 1 - '0']);
}




Contact	PhoneBook::get_user(int index)
{
    return(this->users[index % 8]);
}