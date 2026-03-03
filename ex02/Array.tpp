#ifndef ARRAY_TPP
# define ARRAY_TPP

/**
 * @brief Constructs an empty Array.
 * @return A new empty Array instance.
 */
template <typename T>
Array<T>::Array(void) : data(NULL), count(0) {}

/**
 * @brief Constructs an Array with n default-initialized elements.
 * @param n - Number of elements.
 * @return A new Array instance.
 */
template <typename T>
Array<T>::Array(unsigned int n) : data(NULL), count(n)
{
	if (count == 0)
		return;

	data = new T[count]; // default-initialization for T
}

/**
 * @brief Constructs an Array by copying another one.
 * @param other - Source Array.
 * @return A new copied Array instance.
 */
template <typename T>
Array<T>::Array(const Array& other) : data(NULL), count(0)
{
	*this = other;
}

/**
 * @brief Destroys the Array and releases allocated memory.
 */
template <typename T>
Array<T>::~Array(void)
{
	delete[] data;
}

/**
 * @brief Assigns one Array to another using deep copy.
 * @param other - Source Array.
 * @return Reference to the current Array.
 */
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

/**
 * @brief Provides writable access to an element by index.
 * @param index - Element index.
 * @return Reference to the element at index.
 */
template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= count)
		throw OutOfBounds();
	return data[index];
}

/**
 * @brief Provides read-only access to an element by index.
 * @param index - Element index.
 * @return Const reference to the element at index.
 */
template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= count)
		throw OutOfBounds();
	return data[index];
}

/**
 * @brief Returns the number of elements in the Array.
 * @return Current Array size.
 */
template <typename T>
unsigned int Array<T>::size(void) const
{
	return count;
}

/**
 * @brief Returns the out-of-bounds error message.
 * @return Exception message string.
 */
template <typename T>
const char* Array<T>::OutOfBounds::what() const throw()
{
	return "Array: index out of bounds";
}

#endif