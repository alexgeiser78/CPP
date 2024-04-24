/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:42:27 by ageiser           #+#    #+#             */
/*   Updated: 2024/04/17 19:42:28 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream> //file stream

int replace(char **argv, std::string str)
{
    std::ofstream	        output_file; //output file stream
    std::string::size_type  i;
    std::string::size_type	pos; //position of the word searched
    i = 0;

    output_file.open(std::string(argv[1]) + ".replace"); //opening file
    if (output_file.fail())
		return (1);
    
    
    while(i < str.length())
    {
        pos = str.find(argv[2], i); //finds the position of the word searched, if not found returns -1
		if (pos != std::string::npos && pos == i)
		{
			output_file << argv[3]; //replaces the word searched with the word replacement
			i += std::string(argv[2]).size() - 1; //skip the word replaced
		}
		else
			output_file << str[i]; //if word not found, write the character as it is
        i++;

    }
    output_file.close(); //closing file
    return (0);
}

int main(int argc, char **argv)
{
    std::ifstream input_file; //input file stream
    std::string str;          //contains all the input_file
    char			c;

    if (argc != 4)
	{
		std::cout << "usage: ./losers <filename> <word searched> <word replacement>" << std::endl;
		return (1);
	}
    input_file.open(argv[1]); //opening file
    if (input_file.fail()) //checker for file opening from fstream library
	{
		std::cout << "Error: <" << argv[1] << ">" << \
		" no such file or directory" << std::endl;
		return (1);
	}
    while(!input_file.eof() && input_file >> std::noskipws >> c) //std::noskipws reads whitespace tab and newlines
		str += c;

    input_file.close(); //closing file
    return (replace(argv, str));
}
