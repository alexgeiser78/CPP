/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:09:40 by ageiser           #+#    #+#             */
/*   Updated: 2024/02/27 19:09:44 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
    std::cout << "Contact class constructed" << std::endl;
}

Contact::~Contact(void)
{
    std::cout << "Contact class destructed" << std::endl;
}

std::string Contact::get_firstname(void)
{
    return (this->first_name);
}

void        Contact::set_firstname(std::string first_name)
{
    this->first_name = first_name;
}

std::string Contact::get_lastname(void)
{
    return (this->last_name);
}

void        Contact::set_lastname(std::string last_name)
{
    this->last_name = last_name;
}

std::string Contact::get_nickname(void)
{
    return (this->nickname);
}

void        Contact::set_nickname(std::string nickname)
{
    this->nickname = nickname;
}

std::string Contact::get_phonenumber(void)
{
    return (this->phone_number);
}

void        Contact::set_phonenumber(std::string phone_number)
{
    this->phone_number = phone_number;
}

std::string Contact::get_darkestsecret(void)
{
    return (this->darkest_secret);
}

void        Contact::set_darkestsecret(std::string darkest_secret)
{
    this->darkest_secret = darkest_secret;
}

