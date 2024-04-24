/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:23:45 by ageiser           #+#    #+#             */
/*   Updated: 2024/04/11 18:23:48 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./Zombie.hpp"

/* Returns pointer to Zombie object allocated with new (heap)*/
Zombie	*newZombie(std::string name);

/* Creates new Zombie stored on the heap, which announces itself (stack local variable)*/
void	randomChump(std::string name);

int	main(void)
{
	Zombie	*z = newZombie("Alex:");
	z->announce();
    //z = newZombie("Someone else:"); // This doesn't destroy the previous Zombie object
	randomChump("Foo:");
	delete z; // destroy the heap, destructor destroys the stack
}

/*
-constructor is called with class Zombie object
-announce function with name of Zombie object
-randomChump function with constructor of Zombie object with new name and announce function
-destructor is called with class Zombie object and name of Zombie object
*/
