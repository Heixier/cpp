#include <algorithm>
#include <stdexcept>
#include <iostream>

#include "Span.hpp"

void Span::addNumber(int num)
{
	if (idx + 1 == num_elements)
		throw std::out_of_range("no more space left in array");
	array[idx++] = num;
}

int Span::shortestSpan()
{
	int shortest = *std::min_element(&(array[0]), &(array[idx]));
	int candidate = shortest;
	int dup_flag = 0;
	for (int i = 0; i < idx; i++)
	{
		if (array[i] == shortest && dup_flag == 0)
		{
			dup_flag = 1;
			continue;
		}
		if (array[i] == shortest && dup_flag)
			return (0); sdasd logic bad broke need sleep not difficult 
		if (array[i] > shortest)
		{
			if (!candidate)
				candidate = array[i];
			else if (array[i] < candidate)
				candidate = array[i];
		}
	}
	std::cout << "shortestSpan shortest: " << shortest << "\nshortestSpan candidate: " << candidate << '\n';
	return (candidate - shortest);
}

int Span::longestSpan()
{
	int shortest = *std::min_element(&(array[0]), &(array[idx]));
	int longest = *std::max_element(&(array[0]), &(array[idx]));

	return (longest - shortest);
}

void Span::print_array()
{
	std::cout << "Array length: " << num_elements << "\nArray idx: " << idx << "\n\n";
	for (int i = 0; i < idx; i++)
		std::cout << array[i] << '\n';
}

Span::Span(): num_elements(0), idx(0), array(NULL) { }
Span::Span(unsigned int N): num_elements(N), idx(0), array(NULL) { array = new int[num_elements]; }

Span::Span(const Span& other)
{
	num_elements = other.num_elements;
	idx = other.idx;
	array = new int[num_elements];
	for (int i = 0; i < num_elements; i++)
		array[i] = other.array[i];
}

Span& Span::operator= (const Span& other)
{
	if (this != &other)
	{
		num_elements = other.num_elements;
		idx = other.idx;
		delete[] array;
		array = new int[num_elements];
		for (int i = 0; i < num_elements; i++)
			array[i] = other.array[i];
	}
	return (*this);
}

Span::~Span()
{
	delete[] array;
}