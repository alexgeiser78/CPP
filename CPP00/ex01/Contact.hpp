/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:10:21 by ageiser           #+#    #+#             */
/*   Updated: 2024/02/27 19:10:23 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>


class Contact
{

    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

    public:
        Contact(void);
		~Contact(void);

        std::string get_firstname(void);
        void        set_firstname(std::string first_name);
        std::string get_lastname(void);
        void        set_lastname(std::string last_name);
        std::string get_nickname(void);
        void        set_nickname(std::string nickname);
        std::string get_phonenumber(void);
        void        set_phonenumber(std::string phone_number);
        std::string get_darkestsecret(void);
        void        set_darkestsecret(std::string darkest_secret);    
};

#endif