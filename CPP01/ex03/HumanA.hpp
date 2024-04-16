#include "Weapon.hpp"

class	HumanA
{
    private:
    std::string	_name;
	Weapon		&_weapon; //reference to weapon, ref is not null and cannot be changed

    public:

    HumanA(std::string name, Weapon &weapon);
    ~HumanA(void);
    void	attack(void);
};