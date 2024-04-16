#include "Weapon.hpp"

class	HumanB
{
    private:
		std::string	_name;
		Weapon		*_weapon; //pointer to weapon, can be null and can be changed

    public:
    HumanB(std::string name);
    ~HumanB(void);
    void	attack(void);
    void	setWeapon(Weapon &weapon);
};

