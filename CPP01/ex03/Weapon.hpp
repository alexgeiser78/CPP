#ifndef WEAPON_HPP

# define WEAPON_HPP

# include <iostream>

class Weapon
{
    private:
		std::string	_type;
    public:
    Weapon(std::string type);
    ~Weapon(void);
    const std::string&	getType(void); //const ref to type
    void		setType(std::string type);
};

#endif