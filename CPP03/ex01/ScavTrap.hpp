#ifndef SCARVTRAP_HPP
# define SCARVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap   //inheritance
{
    public: 
        ScavTrap(void);
        ScavTrap(std::string const &name);
        ScavTrap(const ScavTrap &copy);
        ~ScavTrap();
        ScavTrap &operator=(const ScavTrap &copy);
        void guardGate(void);
    private:
        bool _guardingGate;

};




#endif