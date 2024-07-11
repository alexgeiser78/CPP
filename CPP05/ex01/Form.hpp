#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat; //forward declaration, allow the Form class to compile even if the full definition of the Bureaucrat class is not available at that point.

class Form
{
    public:
        Form(void);
        Form(const std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
        Form(const Form &obj);
        ~Form(void);
        Form &operator=(const Form &obj);

        std::string		    getName(void) const;
        bool				getSigned(void) const;
		unsigned int					getGradeToSign(void) const;
		unsigned int					getGradeToExecute(void) const;
		void				beSigned(const Bureaucrat &obj);
        
        class	GradeTooHighException : public std::out_of_range
		{
			public:
				GradeTooHighException(std::string const msg) :
				std::out_of_range(msg) {}
		};
		class	GradeTooLowException : public std::out_of_range
		{
			public:
				GradeTooLowException(std::string const msg) : std::out_of_range(msg) {}
		};

    private:
        std::string const _name;
        bool _signed;
        unsigned int const _gradeToSign;
        unsigned int const _gradeToExecute;
    
};


std::ostream	&operator<<(std::ostream &output, const Form &obj);

#endif