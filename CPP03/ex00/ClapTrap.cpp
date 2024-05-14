#include "ClapTrap.hpp"

//------------------constructors and destructors------------------

ClapTrap::ClapTrap(void): _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " created with default constructor." << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " destroyed." << std::endl;
}

ClapTrap::ClapTrap(std::string const &name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " created." << std::endl;
}


ClapTrap::ClapTrap(ClapTrap const &copy)
{
	std::cout << "ClapTrap " << this->_name << " copied." << std::endl;
	*this = copy;
}

//------------------operators------------------

ClapTrap	&ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "Assignment operator for ClapTrap called." << std::endl;
	this->_name = copy.get_name();
	this->_hitPoints = copy.get_hitPoints();
	this->_energyPoints = copy.get_energyPoints();
	this->_attackDamage = copy.get_attackDamage();
	return (*this);
}

//------------------set and get functions------------------

std::string const	&ClapTrap::get_name(void) const
{
	return (this->_name);
}

int const	&ClapTrap::get_hitPoints(void) const
{
	return (this->_hitPoints);
}

int const	&ClapTrap::get_energyPoints(void) const
{
	return (this->_energyPoints);
}

int const	&ClapTrap::get_attackDamage(void) const
{
	return (this->_attackDamage );
}

void	ClapTrap::set_name(std::string const &name)
{
	this->_name = name;
}

void	ClapTrap::set_hitPoints(int const &value)
{
	this->_hitPoints = value;
}

void	ClapTrap::set_energyPoints(int const &value)
{
	this->_energyPoints = value;
}

void	ClapTrap::set_attackDamage(int const &value)
{
	this->_attackDamage = value;
}