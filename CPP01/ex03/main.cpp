/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:41:18 by ageiser           #+#    #+#             */
/*   Updated: 2024/04/17 19:41:20 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"


int main()
{
    {
    Weapon club = Weapon("crude spiked club"); //club = object of class Weapon with argument "crude spiked club" 
    HumanA bob("Bob", club);                   //bob = object of class HumanA with arguments "Bob" and object club
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
    }
    //class HumanA is destroyed, but the weapon is still in memory
    {
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");  
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
    }
    return 0;
}
