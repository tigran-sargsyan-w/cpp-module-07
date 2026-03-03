#include <iostream>
#include <string>
#include "iter.hpp"

/**
 * @brief Prints an integer value.
 * @param value - Integer to print.
 */
static void	printInt(const int& value)
{
	std::cout << value << std::endl;
}

/**
 * @brief Increments an integer by one.
 * @param value - Integer to increment.
 */
static void	incrementInt(int& value)
{
	value++;
}

/**
 * @brief Prints a string value.
 * @param value - String to print.
 */
static void	printString(const std::string& value)
{
	std::cout << value << std::endl;
}

/**
 * @brief Uppercases the first character if it is lowercase.
 * @param value - String to modify.
 */
static void	toUpperFirstChar(std::string& value)
{
	if (value.size() == 0)
		return ;
	if (value[0] >= 'a' && value[0] <= 'z')
		value[0] = static_cast<char>(value[0] - ('a' - 'A'));
}

/**
 * @brief Runs tests for iter with ints and strings.
 * @return Exit status code.
 */
int main(void)
{
	int numbers[5] = {1, 2, 3, 4, 5};

	std::cout << "Original numbers:" << std::endl;
	iter(numbers, 5, printInt);

	iter(numbers, 5, incrementInt);

	std::cout << "After increment:" << std::endl;
	iter(numbers, 5, printInt);

	std::cout << std::endl;

	const std::string wordsConst[3] = {"hello", "world", "cpp"};
	std::cout << "Const strings (print):" << std::endl;
	iter(wordsConst, 3, printString);

	std::cout << std::endl;

	std::string words[3] = {"hello", "world", "cpp"};
	std::cout << "Before toUpperFirstChar:" << std::endl;
	iter(words, 3, printString);

	iter(words, 3, toUpperFirstChar);

	std::cout << "After toUpperFirstChar:" << std::endl;
	iter(words, 3, printString);

	return 0;
}