#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class	Intern
{
	private:
		typedef AForm	*(Intern::*action)(const std::string target);
		action			actions[3];
		AForm	*_makeShrubbery(const std::string target);
		AForm	*_makePresidential(const std::string target);
		AForm	*_makeRobotomy(const std::string target);
	public:
		Intern(void);
		Intern(const Intern &obj);
		~Intern(void);
		Intern	&operator=(const Intern &obj);

		AForm	*makeForm(std::string formrequest, std::string target);

		class WrongValue : public std::invalid_argument
		{
			public:
				WrongValue(const std::string msg) : std::invalid_argument(msg) {}
		};
};

std::ostream	&operator<<(std::ostream &output, const Intern &obj);
#endif
