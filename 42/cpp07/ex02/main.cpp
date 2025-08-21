#include <iostream>
#include <sys/types.h>
#include <unistd.h>

#include "Array.hpp"
#include "colors.hpp"

int main(void)
{
	Array<unsigned int> uintarr(5);
	std::cout << "Size of uintarr: " << uintarr.size() << '\n';
	std::cout << ICE_BLUE << "\nOriginal: \n" << END;
	for (unsigned int i = 0 ; i < uintarr.size(); i++)
		std::cout << "Arr: [" << i << "] " << uintarr[i] << '\n';

	std::cout << "\nModifying uintarr[1] = 42 and uintarr[3] = 21\n";
	uintarr[1] = 42;
	uintarr[3] = 21;

	std::cout << ICE_BLUE << "\nOriginal: \n" << END;
	for (unsigned int i = 0 ; i < uintarr.size(); i++)
		std::cout << "Arr: [" << i << "] " << uintarr[i] << '\n';

	std::cout << "\nCopying array and checking values: \n";
	Array<unsigned int> copyarr(uintarr);
	std::cout << YELLOW << "Copy: \n" << END;
	for (unsigned int i = 0 ; i < copyarr.size(); i++)
		std::cout << "Arr: [" << i << "] " << copyarr[i] << '\n';

	std::cout << "\nModifying copyarr[2] = 63\n";
	copyarr[2] = 63;
	std::cout << YELLOW << "Copy: \n" << END;
	for (unsigned int i = 0 ; i < copyarr.size(); i++)
		std::cout << "Arr: [" << i << "] " << copyarr[i] << '\n';

	std::cout << "\nMaking sure original was not modified\n";
	std::cout << ICE_BLUE << "\nOriginal: \n" << END;
	for (unsigned int i = 0 ; i < uintarr.size(); i++)
		std::cout << "Arr: [" << i << "] " << uintarr[i] << '\n';

	std::cout << "\nAssigning copy to original and checking values: \n";
	std::cout << ICE_BLUE << "\nOriginal: \n" << END;
	uintarr = copyarr;
	for (unsigned int i = 0 ; i < uintarr.size(); i++)
		std::cout << "Arr: [" << i << "] " << uintarr[i] << '\n';

	std::cout << "\nModifying uintarr[0] = 12 and uintarr[4] = 24\n";
	uintarr[0] = 12;
	uintarr[4] = 24;
	std::cout << ICE_BLUE << "\nOriginal: \n" << END;
	for (unsigned int i = 0 ; i < uintarr.size(); i++)
		std::cout << "Arr: [" << i << "] " << uintarr[i] << '\n';

	std::cout << "\nMaking sure copy was not modified\n";
	std::cout << YELLOW << "Copy: \n" << END;
	for (unsigned int i = 0 ; i < copyarr.size(); i++)
		std::cout << "Arr: [" << i << "] " << copyarr[i] << '\n';

	std::cout << "\nCreating empty array\n";
	Array<long> emptyarr;
	try
	{
		std::cout << "emptyarr: " << &emptyarr << '\n';
		std::cout << "emptyarr size: " << emptyarr.size() << '\n';
		std::cout << "emptyarr[0]: " << emptyarr[0] << '\n';
	}
	catch (std::exception&)
	{
		std::cout << RED << "Exception triggered!\n" << END;
	}

	std::string temp_str_arr[9] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
	Array<std::string> string_arr(9);
	for (int i = 0; i < 9; i++)
		string_arr[i] = temp_str_arr[i];

	std::cout << LIGHT_GREEN << "\nstring_arr: \n" << END;
	for (unsigned int i = 0 ; i < string_arr.size(); i++)
		std::cout << "Arr: [" << i << "] " << string_arr[i] << '\n';

	std::cout << "\nInitialising small_string_arr(3) and assigning it to the bigger string_arr(9)\n";
	std::string small_temp_str_arr[3] = {"the", "clouds", "blow"};
	Array<std::string> small_string_arr(3);
	for (int i = 0; i < 3; i++)
		small_string_arr[i] = small_temp_str_arr[i];

	std::cout << LIGHT_GREEN << "\nsmall_string_arr: \n" << END;
	for (unsigned int i = 0 ; i < small_string_arr.size(); i++)
		std::cout << "Arr: [" << i << "] " << small_string_arr[i] << '\n';

	std::cout << LIGHT_GREEN << "\nsmall_string_arr = string_arr; \n" << END;
	small_string_arr = string_arr;

	std::cout << LIGHT_GREEN << "\nsmall_string_arr: \n" << END;
	for (unsigned int i = 0 ; i < small_string_arr.size(); i++)
		std::cout << "Arr: [" << i << "] " << small_string_arr[i] << '\n';

	std::cout << "\nIncrement string_arr until out of bounds\n";

	try
	{
		for (int i = 0;;i++)
		{
			std::cout << "string_arr: [" << i << "] ";
			std::cout << LIGHT_GREEN << string_arr[i] << '\n' << END;
			sleep(1);
		}
	}
	catch (std::exception&)
	{
		std::cout << RED << "Exception triggered!\n" << END;
	}

	std::cout << ORANGE << "\nMaking a fun array using fun_arr[0] = uintarr and fun_arr[1] = copyarr\n" << END;
	Array<Array<unsigned int> > fun_array(2);
	fun_array[0] = uintarr;
	fun_array[1] = copyarr;

	std::cout << ICE_BLUE << "Original: \n" << END;
	for (unsigned int i = 0 ; i < fun_array[0].size(); i++)
		std::cout << "Arr: [" << i << "] " << fun_array[0][i] << '\n';

	std::cout << YELLOW << "Copy: \n" << END;
	for (unsigned int i = 0 ; i < fun_array[1].size(); i++)
		std::cout << "Arr: [" << i << "] " << fun_array[1][i] << '\n';


	std::cout << ORANGE << "\nMaking a const copy of it to see if attempts to modify elements will still compile (check the code)\n" << END;
	
	const Array<Array<unsigned int> > const_fun_array(fun_array);

	std::cout << ICE_BLUE << "Original: \n" << END;
	for (unsigned int i = 0 ; i < const_fun_array[0].size(); i++)
		std::cout << "Arr: [" << i << "] " << const_fun_array[0][i] << '\n';

	std::cout << YELLOW << "Copy: \n" << END;
	for (unsigned int i = 0 ; i < const_fun_array[1].size(); i++)
		std::cout << "Arr: [" << i << "] " << const_fun_array[1][i] << '\n';

	fun_array[0] = uintarr; // will compile
	// const_fun_array[1] = uintarr; // will not compile
}