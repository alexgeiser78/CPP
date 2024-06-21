#pragma once

#include <iostream>
#include "Brain.hpp"

class Animal
{
	protected:
		std::string	_type;
    
    public:
        Animal(void);
		Animal(std::string const &type);
		Animal(Animal const &copy);
        virtual ~Animal(void); // virtual destructor ensure that the derived object is properly destroyed when called by a base pointer

        Animal const	&operator=(Animal const &copy);

        std::string const	&getType(void) const;
		void				setType(std::string const &type);

        virtual Brain       &get_brain(void) const; //
   

        virtual void		makeSound(void) const; //virtual means that it can be modified by derived classes, important for polymorphism
};