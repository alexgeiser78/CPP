#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib> // For rand()
# include "AForm.hpp"

class	RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &obj);
		~RobotomyRequestForm(void);
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &obj);
		void	execute(Bureaucrat const &executor) const;
		bool	checkRequirement(const Bureaucrat &executor) const;
	private:
		const std::string	_target;
};
#endif