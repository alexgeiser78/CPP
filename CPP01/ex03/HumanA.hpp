/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:40:31 by ageiser           #+#    #+#             */
/*   Updated: 2024/04/17 19:40:32 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
