/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:12:57 by ageiser           #+#    #+#             */
/*   Updated: 2024/02/24 19:13:00 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    int i;
    int j;

    
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else if (argc > 1)
    {
        i = 1;
        while (argv[i])
        {
            j = 0;
            while (argv[i][j])
            {
                std::cout << (char)toupper(argv[i][j]);
                j++;
                
            }
            std::cout << " ";
            i++;
        }
        std::cout << std::endl;
    }
return (0);
}