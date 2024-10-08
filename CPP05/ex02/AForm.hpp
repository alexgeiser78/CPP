#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

//Pure virtual function. This class takes a bureaucrat who was a certain grade.
//if this Bureaucrat can sign the form then it means it's able to execute the
//form. The executable part is done in the derived classes which print their
//own output through the pure virtual function "execute"

class Bureaucrat;

class	AForm
{
	public:
		AForm(void);
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &obj);
		virtual ~AForm(void);
		AForm &operator=(const AForm &obj);

		std::string			getName(void) const;
		bool				getSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;
		void				beSigned(const Bureaucrat &obj);
		void				createDerived(const Bureaucrat &executor);
		virtual void		execute(Bureaucrat const &executor) const = 0;


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
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		virtual bool		checkRequirement(const Bureaucrat &executor) const = 0;
};

std::ostream	&operator<<(std::ostream &output, const AForm &obj);
#endif