/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:28:19 by ageiser           #+#    #+#             */
/*   Updated: 2024/02/27 18:28:23 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream> //cin, cout
#include <string> //string
#include "Contact.hpp"
//#include "PhoneBookUtils.hpp"

class PhoneBook
{
    private:
        Contact users[8];
        int     indux;

    public:
        PhoneBook(void); //Constructor
        ~PhoneBook(void); //Destructor

        void    add(void);
        void    search(void);
        void    print(Contact user);


        Contact get_user(int index);

};
            int    search_flag(Contact users[8]);
        std::string set_width(std::string str, unsigned long width);
    

#endif
