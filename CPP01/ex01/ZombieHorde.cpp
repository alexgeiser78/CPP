/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:35:54 by ageiser           #+#    #+#             */
/*   Updated: 2024/04/17 19:35:55 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//mandatory function

Zombie*	zombieHorde(int N, std::string name)
{
    int i;

    i = 0;
	Zombie *horde = new Zombie[N];
    while(i < N)
    {
        horde[i].setName(name);
        i++;
    }
	return (horde); //return pointer to array of N zombies
}
