#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array(void) : data(NULL), count(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : data(NULL), count(n)
{
	if (count == 0)
		return;

	data = new T[count]; // default-initialization for T
}

template <typename T>
Array<T>::Array(const Array& other) : data(NULL), count(0)
{
	*this = other;
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] data;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this == &other)
		return *this;

	delete[] data;
	data = NULL;
	count = other.count;

	if (count == 0)
		return *this;

	data = new T[count];
	for (unsigned int i = 0; i < count; i++)
		data[i] = other.data[i];
 	
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= count)
		throw OutOfBounds();
	return data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= count)
		throw OutOfBounds();
	return data[index];
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return count;
}

template <typename T>
const char* Array<T>::OutOfBounds::what() const throw()
{
	return "Array: index out of bounds";
}

#endif