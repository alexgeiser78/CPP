#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

//with the override keyword we ensure that this function actually overrides a
//virtual function in the base class.

class	ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &obj);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &obj);
		void	execute(Bureaucrat const &executor) const;
		bool	checkRequirement(const Bureaucrat &executor) const;
	private:
		const std::string	_target;
};
#endif