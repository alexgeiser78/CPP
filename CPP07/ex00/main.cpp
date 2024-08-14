#include "whatever.hpp"

int main() 
{
	int a = 2;
	int b = 35;
	
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap( a, b ); // :: opérateur de résolution de portée
					// ::swap(a, b); bypass any other swap functions that might be in the current scope, and to use the swap function defined in the global namespace.
	std::cout << "swap" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << std::endl;

	std::string c = "string1";
	std::string d = "string2";
	
	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "swap" << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;

	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << std::endl;

	float e = 3.14;
	float f = 1.23;

	std::cout << "e = " << e << ", f = " << f << std::endl;
	::swap(e, f);
	std::cout << "swap" << std::endl;
	std::cout << "e = " << e << ", f = " << f << std::endl;

	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
	std::cout << std::endl;

	return 0;
}