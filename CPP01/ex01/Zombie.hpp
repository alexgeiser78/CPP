#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP

# include <iostream>
# include <algorithm>

/* Zombie Class definition */
class	Zombie
{
	private:
		std::string	_name;
	public:
		Zombie(std::string name);
		Zombie(void);
		~Zombie(void);
		void	announce(void);
		void	setName(std::string name);
};

/* Returns pointer to Zombie object allocated with new */
Zombie	*newZombie(std::string name);

/* Creates new Zombie stored on the heap, which announces itself */
void		randomChump(std::string name);

#endif