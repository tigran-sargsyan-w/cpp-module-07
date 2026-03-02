#include <iostream>
#include <string>
#include "Array.hpp"

static void printIntArray(const Array<int>& arr)
{
	unsigned int i;

	std::cout << "size = " << arr.size() << std::endl;
	i = 0;
	while (i < arr.size())
	{
		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
		i++;
	}
}

int main(void)
{
	Array<int> empty;
	std::cout << "[1] Empty array" << std::endl;
	std::cout << "size = " << empty.size() << std::endl;

	std::cout << "\n[2] Array of 5 ints (default-initialized)" << std::endl;
	Array<int> a(5);
	printIntArray(a);

	std::cout << "\n[3] Write values, then deep copy" << std::endl;
	a[0] = 10;
	a[1] = 20;
	a[2] = 30;

	Array<int> b(a);
	a[1] = 999;

	std::cout << "Original a:" << std::endl;
	printIntArray(a);

	std::cout << "Copy b (must keep old value at index 1):" << std::endl;
	printIntArray(b);

	std::cout << "\n[4] Assignment operator deep copy" << std::endl;
	Array<int> c;
	c = a;
	a[0] = 777;

	std::cout << "a:" << std::endl;
	printIntArray(a);

	std::cout << "c (must keep old value at index 0):" << std::endl;
	printIntArray(c);

	std::cout << "\n[5] Bounds check (should throw)" << std::endl;
	try
	{
		std::cout << a[100] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "caught: " << e.what() << std::endl;
	}

	std::cout << "\n[6] Const operator[]" << std::endl;
	const Array<std::string> s(2);
	try
	{
		std::cout << "s[0] = " << s[0] << std::endl;
		std::cout << "s[1] = " << s[1] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "caught: " << e.what() << std::endl;
	}

	return 0;
}