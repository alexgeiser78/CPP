/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:40:46 by ageiser           #+#    #+#             */
/*   Updated: 2024/04/17 19:40:48 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

