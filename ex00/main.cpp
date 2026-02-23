#include <iostream>
#include <string>
#include "whatever.hpp"

// void showErrorCases()
// {
// 	class A {};
// 	A x;
// 	A y;
// 	::min(x, y); // <- there will be an error here
// 	::min(a, y); // <- there will be an error here
// }

int main(void)
{
	int a = 2;
	int b = 3;

	// showErrorCases(); // comment this line to avoid the error cases
	
    ::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	return 0;
}