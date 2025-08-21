#ifndef INFO_HPP
#define INFO_HPP

template <typename Ptr, typename Len>
void info(Ptr& array, Len length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << array[i] << '\n';
	}
}

#endif