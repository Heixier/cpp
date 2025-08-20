#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& x, T& y)
{
	T tmp = x;
	x = y;
	y = tmp;
}

template <typename T>
T& min(T& x, T& y) { return (y <= x ? y : x); }

template <typename T>
T& max(T& x, T& y) { return (y >= x ? y : x); }

#endif
