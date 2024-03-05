#ifndef PHONEBOOK_UTILS_HPP

# define PHONEBOOK_UTILS_HPP

# include "Contact.hpp"

/* Returns a string with n spaces */
std::string	add_spaces(int n);

/* Ensures a string has at most 'max' chars, adding '.' when needed */
std::string	set_width(std::string str, long unsigned max);

/* Prints existing contacts with a pretty format */
int    search_flag(Contact users[8]);

#endif