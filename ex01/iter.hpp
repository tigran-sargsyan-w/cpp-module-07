#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef> // size_t

template <typename T>
void	iter(T* array, const size_t length, void (*func)(T&))
{
	size_t index;

	if (!array || !func)
		return ;
	index = 0;
	while (index < length)
	{
		func(array[index]);
		index++;
	}
}

template <typename T>
void	iter(const T* array, const size_t length, void (*func)(const T&))
{
	size_t index;

	if (!array || !func)
		return ;
	index = 0;
	while (index < length)
	{
		func(array[index]);
		index++;
	}
}

#endif