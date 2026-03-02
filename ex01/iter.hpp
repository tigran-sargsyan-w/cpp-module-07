#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef> // size_t

template <typename T>
void	iter(T* array, const size_t length, void (*func)(T&))
{
	if (!array || !func)
		return ;
	for (size_t index = 0; index < length; ++index)
	{
		func(array[index]);
	}
}

template <typename T>
void	iter(const T* array, const size_t length, void (*func)(const T&))
{
	if (!array || !func)
		return ;
	for (size_t index = 0; index < length; ++index)
	{
		func(array[index]);
	}
}

#endif