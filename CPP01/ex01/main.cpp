/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:35:18 by ageiser           #+#    #+#             */
/*   Updated: 2024/04/17 19:35:20 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* Creates horde of zombies named 'name' */
Zombie*	zombieHorde(int N, std::string name);

int	main(void)
{
	int	size;
    int i;

	size = 10;
    i = 0;
	Zombie *horde = zombieHorde(size, "Zombitos:"); //array of 10 zombies named
	while(i < size)
	{
		horde[i].announce(); //each zombie announces itself
		i++;
	}
	delete [] horde;
}
