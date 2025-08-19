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
	std::cout << std::left << std::setw(32) << "original_ptr -> anything_you = " << ICE_BLUE << "42\n" << END;
	original_ptr -> anything_you = 42;
	std::cout << std::left << std::setw(32) << "original_ptr -> literally = " << ICE_BLUE << "forty two\n" << END;
	original_ptr -> literally = "forty two";
	std::cout << std::left << std::setw(32) << "original_ptr -> you_should = " << ICE_BLUE << "4242\n\n" << END;
	original_ptr -> you_should = 4242;

	std::cout << std::left << std::setw(32) << "Original Data ptr address: " << &data_ptr << '\n';

	Data* serialized_ptr = Serializer::deserialize(Serializer::serialize(&data_ptr));
	std::cout << std::left << std::setw(32) << "Calling deserialize: " << serialized_ptr << '\n';

	if (serialized_ptr == original_ptr)
		std::cout << LIGHT_GREEN << "Match!\n\n" << END;
	else
		std::cout << RED << "Mismatch!\n\n" << END;

	std::cout << ICE_BLUE << "Check if values can be re-accessed\n" << END;
	std::cout << std::left << std::setw(32) << "serialized_ptr -> anything_you: " << ICE_BLUE << serialized_ptr -> anything_you << '\n' << END;
	std::cout << std::left << std::setw(32) << "serialized_ptr -> literally: " << ICE_BLUE << serialized_ptr -> literally << '\n' << END;
	std::cout << std::left << std::setw(32) << "serialized_ptr -> you_should: " << ICE_BLUE << serialized_ptr -> you_should << "\n\n" << END;

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
	std::cout << ICE_BLUE << "Check if values can be re-accessed using incremented_ptr -> value (no)\n" << END;
	std::cout << RED << "Enter any key to continue with the segfault\n" << END;
	std::cin.get();

	std::cout << std::left << std::setw(32) << "incremented_ptr -> anything_you: " << ICE_BLUE << incremented_ptr -> anything_you << '\n' << END;
	std::cout << std::left << std::setw(32) << "incremented_ptr -> literally: " << ICE_BLUE << incremented_ptr -> literally << '\n' << END;
	std::cout << std::left << std::setw(32) << "incremented_ptr -> you_should: " << ICE_BLUE << incremented_ptr -> you_should << "\n\n" << END;
	#endif
}