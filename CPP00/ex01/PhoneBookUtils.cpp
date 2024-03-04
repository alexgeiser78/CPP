#include "PhoneBook.hpp"


std::string set_width(std::string str, unsigned long width)  //width of 10 max
{
    if (str.length() > width)
    {
        str.resize(width);
        str[width - 1] = '.';
    }
    return (str);
}

int	search_flag(Contact users[8])
{
    std::string str;
    int i;

    i = 0;
    while (i < 8)
    {
        if (users[i].get_firstname() != "")
        {
            std::cout << set_width(users[i].get_firstname(), 10) << "|";
            std::cout << set_width(users[i].get_lastname(), 10) << "|";
            std::cout << set_width(users[i].get_nickname(), 10) << "|" << std::endl;
        }
        i++;
    }
    std::cout << "Enter the index of the user you want to see: ";
    std::getline(std::cin, str);
    if (str.length() == 1 && str[0] >= '0' && str[0] <= '7')
    {
        i = str[0] - '0';
        if (users[i].get_firstname() != "")
        {
            std::cout << "First name: " << users[i].get_firstname() << std::endl;
            std::cout << "Last name: " << users[i].get_lastname() << std::endl;
            std::cout << "Nickname: " << users[i].get_nickname() << std::endl;
            std::cout << "Phone number: " << users[i].get_phonenumber() << std::endl;
            std::cout << "Darkest secret: " << users[i].get_darkestsecret() << std::endl;
        }
        else
            std::cout << "No user with this index" << std::endl;
    }
    else
        std::cout << "Invalid input" << std::endl;
    return (i);
}