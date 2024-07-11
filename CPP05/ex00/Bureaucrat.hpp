#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>


class Bureaucrat
{
    public:
        Bureaucrat(void);
        Bureaucrat (const std::string name, unsigned int grade);
        Bureaucrat(const Bureaucrat &obj);
        ~Bureaucrat(void);
        Bureaucrat &operator=(const Bureaucrat &obj);

        std::string		getName(void) const;
		unsigned int	getGrade(void) const;
        void			incrementGrade(void);
		void			decrementGrade(void);

        class	GradeTooLowException : public std::out_of_range //more specific than std::exception
        {
            public:
                GradeTooLowException(std::string const msg): std::out_of_range(msg){}
        };

        class	GradeTooHighException : public std::out_of_range
        {
            public:
                GradeTooHighException(std::string const msg): std::out_of_range(msg){}
        };

    private:
        std::string _name;
        unsigned int _grade;
};



    std::ostream	&operator<<(std::ostream &output, const Bureaucrat &obj); //insertion overload
    //std::ostream &output: This is a reference to an std::ostream object, which represents the output stream
    //const Bureaucrat &obj: This is a reference to a constant Bureaucrat object

# endif