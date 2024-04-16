#include <iostream>
#include <fstream> //file stream

int replace(char **argv, std::string str)
{
    std::ofstream	output_file; //output file stream
    output_file.open(std::string(argv[1]) + ".replace"); //opening file
    if (output_file.fail())
		return (1);
    output_file.close(); //closing file
    return (0);
}

int main(int argc, char **argv)
{
    std::ifstream input_file; //input file stream
    std::string str;

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

    input_file.close(); //closing file
    return (replace(argv, str));
}