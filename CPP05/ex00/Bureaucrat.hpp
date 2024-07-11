#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
    public:
        Bureaucrat(void);
        Bureaucrat (const std::string name, unsigned int grade);
        Bureaucrat(const Bureaucrat &obj);
        ~Bureaucrat(void);
        Bureaucrat &operator=(const Bureaucrat &obj);

    private:
        std::string _name;
        unsigned int _grade;
};











# endif