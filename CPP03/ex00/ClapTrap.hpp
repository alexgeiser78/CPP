#ifndef CLAPTRAP_HPP

# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
    private:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
    
    public:
        ClapTrap(void);
		ClapTrap(std::string const &name);
		ClapTrap(ClapTrap const &copy);
		~ClapTrap(void);

        void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

        ClapTrap	&operator=(ClapTrap const &copy);

        std::string const	&get_name(void) const;
		int const			&get_hitPoints(void) const;
		int const			&get_energyPoints(void) const;
		int const			&get_attackDamage(void) const;
		void				set_name(std::string const &name);
		void				set_hitPoints(int const &value);
		void				set_energyPoints(int const &value);
		void				set_attackDamage(int const &value);

};



#endif