#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
	public:
		unsigned int size() const
		{
			return (m_elements);
		}

		T& operator[] (const unsigned int index)
		{
			if (index >= m_elements)
				throw std::exception();
			return (m_data[index]);
		}

		const T& operator[] (const unsigned int index) const
		{
			if (index >= m_elements)
				throw std::exception();
			return (m_data[index]);
		}

		Array(): m_data(NULL), m_elements(0) { }

		Array(unsigned int n): m_data(new T[n]()), m_elements(n) { }

		Array(const Array& other): m_elements(other.m_elements)
		{
			m_data = new T[m_elements];
			for (unsigned int i = 0; i < m_elements; i++)
				m_data[i] = other.m_data[i];
		}

		Array& operator= (const Array& other)
		{
			if (this != &other)
			{
				delete[] m_data;
				m_elements = other.m_elements;
				m_data = new T[m_elements];
				for (unsigned int i = 0; i < m_elements; i++)
				{
					m_data[i] = other.m_data[i];
				}
			}
			return (*this);

		}

		~Array()
		{
			delete[] m_data;
		}

	private:
		T* m_data;
		unsigned int m_elements;

};

#endif