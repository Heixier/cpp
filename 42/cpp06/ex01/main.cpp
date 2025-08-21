#include <iostream>
#include <stdint.h>
#include <iomanip>

#include "colors.hpp"
#include "Serializer.hpp"

int main(void)
{
	Data data_ptr;
	Data* original_ptr = &data_ptr;

	std::cout << ICE_BLUE << "Initialising some values" << '\n' << END;
	std::cout << std::left << std::setw(32) << "original_ptr -> first = " << ICE_BLUE << "forty two\n" << END;
	original_ptr -> first = "forty two";
	std::cout << std::left << std::setw(32) << "original_ptr -> second = " << ICE_BLUE << "42.0f\n" << END;
	original_ptr -> second = 42.0f;
	std::cout << std::left << std::setw(32) << "original_ptr -> third = " << ICE_BLUE << "extra\n\n" << END;
	original_ptr -> third = "extra";

	std::cout << std::left << std::setw(32) << "Original Data ptr address: " << &data_ptr << '\n';

	Data* serialized_ptr = Serializer::deserialize(Serializer::serialize(&data_ptr));
	std::cout << std::left << std::setw(32) << "Calling deserialize: " << serialized_ptr << '\n';

	if (serialized_ptr == original_ptr)
		std::cout << LIGHT_GREEN << "Match!\n\n" << END;
	else
		std::cout << RED << "Mismatch!\n\n" << END;

	std::cout << ICE_BLUE << "Check if values can be re-accessed\n" << END;
	std::cout << std::left << std::setw(32) << "serialized_ptr -> first: " << ICE_BLUE << serialized_ptr -> first << '\n' << END;
	std::cout << std::left << std::setw(32) << "serialized_ptr -> second: " << ICE_BLUE << serialized_ptr -> second << '\n' << END;
	std::cout << std::left << std::setw(32) << "serialized_ptr -> third: " << ICE_BLUE << serialized_ptr -> third << "\n\n" << END;

	uintptr_t mismatch_ptr = Serializer::serialize(original_ptr);
	std::cout << std::left << std::setw(32) << "uintptr_t after serialization: " << mismatch_ptr << '\n';

	mismatch_ptr++;
	std::cout << std::left << std::setw(32) << "Incrementing uintptr_t ptr: " << mismatch_ptr << '\n';

	Data* incremented_ptr = Serializer::deserialize(mismatch_ptr);
	std::cout << std::left << std::setw(32) << "Data ptr from deserialize: " << incremented_ptr << '\n';
	std::cout << std::left << std::setw(32) << "Original Data ptr address: " << original_ptr << '\n';

	if (original_ptr == incremented_ptr)
		std::cout << LIGHT_GREEN << "Match!\n\n" << END;
	else
		std::cout << RED << "Mismatch!\n\n" << END;

	#ifdef SEGFAULT // make segfault
	std::cout << YELLOW << "DEMONSTRATING WHY REINTERPRET CAST IS DANGEROUS BY " << RED << "INTENTIONALLY" << YELLOW << " CAUSING A SEGFAULT:\n\n" << END;
	std::cout << ICE_BLUE << "Create a SmallerData struct (size: " << sizeof(SmallerData) << " bytes vs " << sizeof(Data) << " bytes) and reinterpret_cast it to a Data* pointer\n" << END;
	SmallerData smaller_data;
	Data* faulty_data_ptr = reinterpret_cast<Data *>(&smaller_data);

	std::cout << ICE_BLUE << "Try to modify the third value:\nData* faulty_data_ptr -> third = \"SIGSEGV\"\n";
	std::cout << RED << "Enter any key to continue with the segfault\n" << END;
	std::cin.get();

	faulty_data_ptr -> third = "SIGSEGV";
	std::cout << faulty_data_ptr -> third << '\n';
	#endif
}