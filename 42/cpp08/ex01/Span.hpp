#ifndef SPAN_HPP
#define SPAN_HPP

class Span
{
	public:
		void addNumber(int num);
		int shortestSpan();
		int longestSpan();
		void print_array();

		template <typename InputIt>
		void extend(InputIt first, InputIt last)
		{
			InputIt idx = first;
			
			while (idx != last)
			{
				addNumber(*idx);
				idx++;				
			}
		}
		
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator= (const Span& other);
		~Span();

	private:
		int num_elements;
		int idx;
		int* array;

};

#endif