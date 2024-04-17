/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:41:52 by ageiser           #+#    #+#             */
/*   Updated: 2024/04/17 19:41:55 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
